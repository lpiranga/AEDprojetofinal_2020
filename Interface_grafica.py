
import pygame

pygame.init()

 #define o tamanho da janela
janela_largura = 1024
janela_altura = 600

#define as cores
preto = (0, 0, 0)
branco = (255, 255, 255)
azul = (0, 0, 255)
verde = (0, 255, 0)
vermelho = (255, 0, 0)
amarelo = (255, 255, 0)
lilas = (128, 0, 255)

clock = pygame.time.Clock()

#cria a janela do programa
win = pygame.display.set_mode((janela_largura, janela_altura))
pygame.display.set_caption("Momento")

font = pygame.font.SysFont('comicsans', 25)

#define as propriedades do botão
class butao():
  def __init__(self, color, x, y, width, height, text=''):
    self.color = color
    self.x = x
    self.y = y
    self.width = width
    self.height = height
    self.text = text

  def draw(self, win, outline=None):
    # Call this method to draw the button on the screen
    if outline:
      pygame.draw.rect(win, outline, (self.x - 4, self.y - 4, self.width + 8, self.height + 8), 0)

    pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.height), 0)

    if self.text != '':
      text = font.render(self.text, True, (0, 0, 0))
      win.blit(text,
               (self.x + (self.width / 2 - text.get_width() / 2), self.y + (self.height / 2 - text.get_height() / 2)))

  def isOver(self, pos):
    # Pos is the mouse position or a tuple of (x,y) coordinates
    if pos[0] > self.x and pos[0] < self.x + self.width:
      if pos[1] > self.y and pos[1] < self.y + self.height:
        return True
#define as propriedades da caixa
class textbox():
  def __init__(self, x, y, l, h, text=''):
    self.rect = pygame.Rect(x, y, l, h)
    self.x = x
    self.y = y
    self.l = l
    self.h = h
    self.color = amarelo
    self.text = text
    self.txt_surface = font.render(text, True, branco, self.color )
    self.ativo =False

#checa se vc clicou dentro ou fora da caixa
  def digitar(self, event):
    if event.type == pygame.MOUSEBUTTONDOWN:

      if self.rect.collidepoint(pos):
        self.ativo = True
      else:
        self.ativo = False
#Lê as teclas e forma o texto
    if event.type == pygame.KEYDOWN:
      if self.ativo:
        if event.key == pygame.K_RETURN:  #Tecla Enter
          print(self.text)
          self.text = ''
        elif event.key == pygame.K_BACKSPACE: #Apaga a ultima letra registrada
          self.text = self.text[0:-1]
        else:
          self.text += event.unicode

#desenha a caixa na tela
  def draw(self, win):
    win.blit(self.txt_surface, (self.rect.x+5,self.rect.y+5))
    pygame.draw.rect(win, self.color, self.rect, 2, )
    if self.text != '': #coloca o texto dentro da caixa
      text = font.render(self.text, True, branco)
      win.blit(text,
               (self.x + (self.l / 2 - text.get_width() / 2), self.y + (self.h / 2 - text.get_height() / 2)))


def redesenho():
  win.fill(preto)
  botaoverde.draw(win)
  texto1.draw(win)

#onde criamos os botões e as caixas
botaoverde = butao((0, 255, 0), 150, 225, 250, 100, 'Teste')
texto1 = textbox(450, 100, 140, 38)
caixasdetexto = [texto1]

#running loop
run = True
while run:
#atualiza o texto das caixas e os botões
  redesenho()
  pygame.display.update()

  #event handler
  for event in pygame.event.get():
    pos = pygame.mouse.get_pos()  #salva as coordenadas do mouse

    #handle text input
    if event.type == pygame.TEXTINPUT:
      print(event)

    #quit program
    if event.type == pygame.QUIT:
      run = False
      pygame.quit()
      quit()
#função detecta o pressionar do botão
    if event.type == pygame.MOUSEBUTTONDOWN:
      if botaoverde.isOver(pos):
        print('apertou o botao')
#só muda a cor do botão quand passa o mouse encima()
    if event.type == pygame.MOUSEMOTION:
      if botaoverde.isOver(pos):
        botaoverde.color = amarelo
      else:
        botaoverde.color = verde

    for box in caixasdetexto:
      box.digitar(event)

  for box in caixasdetexto:
    box.draw(win)

  clock.tick(30)

  #update display
  pygame.display.flip()

pygame.quit()