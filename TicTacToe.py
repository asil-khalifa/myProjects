'''
0123456789012345
     |     |        1
  x  |     |        2
_____|_____|_____   3
     |     |        4
     |     |        5
_____|_____|_____   6
     |     |        7
     |     |        8
     |     |        9
'''

# places_list = [[2, 2], [2, 8], [2, 14], [5, 2], [5, 8], [5, 14], [8, 2], [8, 8], [8, 14]]
x_places = {2:[], 5:[], 8:[]} #* row:[columns] [2, 8, 14]
o_places = {2:[], 5:[], 8:[]}   
places = []


turn = 0
while True: 
    for row in range(1, 10): 
        if row == 3 or row == 6:
            print('_'*5+'|'+'_'*5+'|'+'_'*5)
        elif row in x_places.keys() and x_places[row]!=[] or row in o_places.keys() and o_places[row]!=[]:
            col_str_ = ' '*5+'|'+' '*5+'|'+' '*5
            col_str = ''
            for col in range(17):
                if col in x_places[row]:
                    col_str += 'x'          
                elif col in o_places[row]:
                    col_str += 'o'
                else:
                    col_str += col_str_[col]
            print(col_str)
        else:
            print(' '*5+'|'+' '*5+'|'+' '*5)    
    
    if turn %2 == 0:
        player = 'x'
    else:
        player = 'o'
    
    def who_won(pl, p):
        global turn
        va = list(pl.values())
        message = f'Player {p} won this match!'

        if set(pl[8]).intersection(set(pl[2]).intersection(set(pl[5]))) != set([]):
            print(message)
            turn = 10

        elif 8 in va[1]:
            if 2 in va[0] and 14 in va[2]:
                print(message)
                turn = 10
            elif 14 in va[0] and 2 in va[2]:
                print(message)
                turn = 10

        else:
            for val in va:
                if len(val) == 3:
                    print(message)
                    turn = 10
                    break

    who_won(o_places, 'O')
    who_won(x_places, 'X')
    turn += 1
    if turn == 11:
        break
    elif turn == 10:
        print('It\'s a draw!')
        break

    while True:
        move = input(f'It\'s {player}\'s turn: ')
        if move.isdigit():
            move = int(move)
            if 0<move<10 and move not in places:
                places.append(move)
                for row in range(2, 9, 3):
                    for col in range(2, 15, 6):
                        move -= 1
                        if move==0:
                            break
                    if move == 0:
                        break
                if player == 'o':
                    o_places[row].append(col)
                else:
                    x_places[row].append(col)
                break
            else:
                print('Invalid input! Try Again.')
        else:
            print('Invalid input! Try again.')        
