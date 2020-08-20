import pygame
import random
import time

BackgroundColour = (155, 155, 155)
ScoreTextColour = (255, 255, 255)

'''
U should change screen width and height if u have a 4k monitor and want the best experience.
It might make the game easier tho bc obstacles/enemies are more spread out but whatever u can add 
more if u want to. I made this on a hackintosh, hence the wierd screen height, the dock is 
annoying and autohide doesnt work lol.
'''
ScreenWidth = 1920
ScreenHeight = 955

#Creates a random number between 0 and 1920 so i don't have to do it like 3 times, cleans up code
def RandY(EntityWidth):
    return random.randint(0, ScreenWidth - EntityWidth)

#Information about player change this to change player starting pos and other stuff like colour
PlayerColour =  (255, 255, 255)
PlayerWidth = 50
PlayerHeight = 50
PlayerPos = [ScreenWidth / 2, ScreenHeight - 70]

#Enemy Information, change for different enemy I guess
EnemyColour =  (0, 0, 0)
EnemyWidth = 50
EnemyHeight = 50
EnemyPos = [RandY(EnemyWidth), 0]
EnemySpeed = EnemyHeight

#List of enemies in the game & their pos
EnemyList = [EnemyPos]

#how many enemies in the game
EnemyCount = 60

#Initializes the display, and the clock. The clock controlles tick speed/frame rate, don't change

score = 0

game_over = False

pygame.init()
screen = pygame.display.set_mode((ScreenWidth, ScreenHeight))
clock = pygame.time.Clock()
font = pygame.font.Font('/Users/nathan/Downloads/ubuntu-font-family-0.83/Ubuntu-L.ttf', 35)

#function that checks if players and obstacles are colliding
def CollisionChecker(PlayerPos, EnemyPos):
    px = PlayerPos[0]
    py = PlayerPos[1]
    ox = EnemyPos[0]
    oy = EnemyPos[1]
    if ox >= px and ox < px + PlayerWidth and oy >= py and oy < py + PlayerHeight:
        return True
    elif px >= ox and px < ox + EnemyWidth and py >= oy and py < oy + EnemyWidth:
        return True
    else:
        return False

#Adds enemies to the enemy list
def DropEnemies(EnemyList, EnemyCount):
    delay = random.random()
    if len(EnemyList) < EnemyCount and delay < 0.1 + score * 0.01:
        XPos = RandY(EnemyWidth)
        YPos = 0
        EnemyList.append([XPos, YPos])
        
#Draws all the enemies in the enemy list on the screen.
def DrawEnemies(EnemyList):
    for EnemyPos in EnemyList:
        pygame.draw.rect(screen, EnemyColour, (EnemyPos[0], EnemyPos[1], EnemyWidth, EnemyHeight))

#Updates the enemy position on the screen
def UpdateEnemyPos(EnemyList):
    for idx, EnemyPos in enumerate(EnemyList):
        if EnemyPos[1] >= 0 and EnemyPos[1] < ScreenHeight:
            EnemyPos[1] += EnemySpeed
        else:
            global score
            score += 1
            print(score)
            EnemyList.pop(idx)

#Checks if the enemy is touching a player
def OnEnemyCollide(EnemyList, PlayerPos):
    for EnemyPos in EnemyList:
         if CollisionChecker(PlayerPos, EnemyPos):
             return True
    return False     
        


while True:
     for event in pygame.event.get():
          if event.type == pygame.QUIT:
              pygame.quit() 
              break
               
          if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT or event.key == pygame.K_a:
                      PlayerPos[0] -= PlayerWidth
          
          if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                      PlayerPos[0] += PlayerWidth 
     
        
     screen.fill(BackgroundColour)
     text = 'Score:' + str(score)
     label = font.render(text, 1, ScoreTextColour)
     screen.blit(label, (20, 20))
     
     clock.tick(10 + score * 0.1)
     UpdateEnemyPos(EnemyList)
     DrawEnemies(EnemyList)
     pygame.draw.rect(screen, PlayerColour, (PlayerPos[0], PlayerPos[1], PlayerWidth, PlayerHeight))
     pygame.display.update ()
     if PlayerPos[0] <= 0 or PlayerPos[0] + PlayerWidth >= ScreenWidth:
         PlayerPos[0] = ScreenWidth / 2
     if CollisionChecker(PlayerPos, EnemyPos):
         break
     
     DropEnemies(EnemyList, EnemyCount)
     
     if OnEnemyCollide(EnemyList, PlayerPos):
         break


time.sleep(3)
