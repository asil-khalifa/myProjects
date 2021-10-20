import time, random
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
available_places = [1, 2, 3, 4, 5, 6, 7, 8, 9]

while True:
    choice = input('''What do you want to play?
    1. Two player game
    2. Play against Computer\n''')
    if choice == '1':
        break
    elif choice =='2':
        first = input('''Do you want to:
    1. Go first
    2. Play second\n''')
        if first == '1' or first =='2':
            break
        else:
            print('Invalid option! Try again.')
            del(first)
    else:
        print('Invalid option! Try again.')

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
    
    def first_player(player1, player2):
        global player
        if turn%2 == 0:
            player = player1
        else:
            player = player2
    
    if choice == '1':
        first_player('x', 'o')
    elif first =='1':
        first_player('You', 'computer')
    else:
        first_player('computer', 'You')
    
    def who_won(pl, p):
        global turn
        va = list(pl.values())
        message = f'{p} won this match!'

        if set(pl[8]).intersection(set(pl[2]).intersection(set(pl[5]))) != set([]):
            print(message)
            turn = 10
            return True

        elif 8 in va[1]:
            if 2 in va[0] and 14 in va[2] or 14 in va[0] and 2 in va[2]:
                print(message)
                turn = 10
                return True

        for val in va:
            if len(val) == 3:
                print(message)
                turn = 10
                return True

    if choice == '1':
        who_won(o_places, 'O')
        who_won(x_places, 'X')

    else:
        who_won(x_places, 'You')
        who_won(o_places, 'Computer') 

    turn += 1
    if turn == 11:
        break
    elif turn == 10:
        print('It\'s a draw!')
        break

    while True:
        if player in 'xo':
            move = input(f'It\'s {player}\'s turn: ')
        elif player == 'You':
            move = input('It\'s your turn!')
        else:
            print('Computer is making move...')
            time.sleep(0.3)
            def convert_to_move(row, col):
                move =0
                for ro in range(2, row, 3):
                    move += 3
                for co in range(2, col+1, 6):
                    move +=1
                return move

            def smart_move():
                move = 0
                #OO_ situation:
                def OO_(us, oppo):                                   #* our_places, oppo_places
                    for key, value in us.items():
                        if len(value) == 2 and oppo[key] == []:
                            empty_col = {2, 8, 14} - set(value)
                            for element in empty_col:
                                e_col = element
                            move = convert_to_move(key, e_col)
                            return move
                
                def O_nxtline(us, oppo):
                    l = [2, 5, 8, 2, 5]
                    for i in range(3):
                        a = set(us[l[i]]).intersection(set(us[l[i+1]]))
                        if a != set([]):
                            for element in a:
                                if element not in oppo[l[i+2]]:
                                    return convert_to_move(l[i+2], element)

                def diagnol(us, oppo): 
                   #[(2, 2), (5, 8), (8, 14)] and [(8, 2), (5, 8), (2, 14)]
                   comb = [((8, 2), (5, 8), (2, 14)),((5, 8), (2, 14), (8, 2)),((8, 2), (2, 14), (5, 8)),((2, 2), (8, 14), (5, 8)),((5, 8), (8, 14), (2, 2)),((2, 2), (5, 8), (8, 14))]
                   for x, y,z in comb:
                       if x[1] in us[x[0]] and y[1] in us[y[0]] and z[1] not in oppo[z[0]]:
                           return convert_to_move(z[0], z[1])

                       

                       


                functions = [OO_, O_nxtline, diagnol]
                for j in functions:
                    if j(o_places, x_places) != None:
                        return j(o_places, x_places)
                for j in functions:
                    if j(x_places, o_places) != None:
                        return j(x_places, o_places)
                return move



            if smart_move() == 0:
                move = str(random.choice(available_places))
            else:
                move = str(smart_move())
            print('Computer chose', move)
                

        if move.isdigit():
            move = int(move)
            if 0<move<10 and move not in places:
                places.append(move)
                available_places.remove(move)
                for row in range(2, 9, 3):
                    for col in range(2, 15, 6):
                        move -= 1
                        if move==0:
                            break
                    if move == 0:
                        break
                if player in 'computer':
                    o_places[row].append(col)
                elif player =='x' or player == 'You':
                    x_places[row].append(col)
                break
            else:
                print('Invalid input! Try Again.')
        else:
            print('Invalid input! Try again.')        
    print('\n\n')
