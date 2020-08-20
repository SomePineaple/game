#!/usr/bin/env python3

import pygame
import random
import time
import tkinter as tk
import math

root = tk.Tk()

ScreenWidth = root.winfo_screenwidth()
ScreenHeight = root.winfo_screenheight()

BackgroundColour = (155, 155, 155)
ScoreTextColour = (255, 255, 255)

#Creates a random number between 0 and 1920 so i don't have to do it like 3 times, cleans up code
def RandY(EntityWidth):
    return random.randint(0, ScreenWidth - EntityWidth)

#Information about player change this to change player starting pos and other stuff like colour
PlayerColour =  (255, 255, 255)
PlayerPos = [ScreenWidth / 2, ScreenHeight - 70]
Player = pygame.image.load('assets/Player.png')

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
font = pygame.font.Font('/Users/nathy/Desktop/ubuntu-font-family-0.83/Ubuntu-L.ttf', 35)
pygame.display.set_caption('Worlds best game')
pygame.display.toggle_fullscreen()

#function that checks if players and obstacles are colliding
def CollisionChecker(PlayerPos, EnemyPos):
    px = PlayerPos[0]
    py = PlayerPos[1]
    ox = EnemyPos[0]
    oy = EnemyPos[1]
    if ox >= px and ox < px + 50 and oy >= py and oy < py + 50:
        return True
    elif px >= ox and px < ox + EnemyWidth and py >= oy and py < oy + EnemyWidth:
        return True
    else:
        return False

#Adds enemies to the enemy list
def DropEnemies(EnemyList, EnemyCount):
    delay = random.random()
    if len(EnemyList) < EnemyCount and delay < 0.02 + score * 0.002:
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
        
def KeyManager():
    if pygame.key.get_pressed() [pygame.K_LEFT] or pygame.key.get_pressed() [pygame.K_a]:
        PlayerPos[0] -= 13
    elif pygame.key.get_pressed() [pygame.K_RIGHT] or pygame.key.get_pressed() [pygame.K_d]:
        PlayerPos[0] += 13

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit() 
            break
            
    
        
    screen.fill(BackgroundColour)

    KeyManager()

    UpdateEnemyPos(EnemyList)
    DrawEnemies(EnemyList)

    EnemySpeed = 15 + math.floor(score * 0.01)

    text = 'Score:' + str(score)
    label = font.render(text, 1, ScoreTextColour)
    screen.blit(label, (20, 20))

    screen.blit(Player, PlayerPos)
    pygame.display.flip()
    if PlayerPos[0] <= 0 or PlayerPos[0] + 50 >= ScreenWidth:
        PlayerPos[0] = ScreenWidth / 2
    
    DropEnemies(EnemyList, EnemyCount)
    
    if OnEnemyCollide(EnemyList, PlayerPos):
        break

    clock.tick(60)


#End screen
time.sleep(1)
font = pygame.font.Font('/Users/nathy/Desktop/ubuntu-font-family-0.83/Ubuntu-L.ttf', 50)
screen.fill((255, 255, 255))
endText = 'Your final score was ' + str(score)

endLabel = font.render(endText, 1, (100, 100, 100))

textWidth, textHeight = font.size(endText)

textX = int((ScreenWidth / 2) - (textWidth / 2))
textY = int((ScreenHeight / 2) - (textHeight / 2))

screen.blit(endLabel, (textX, textY))
pygame.display.flip()

time.sleep(5)
