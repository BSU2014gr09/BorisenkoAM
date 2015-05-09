#include <iostream>
#include "queue.h"
#include <conio.h>
using namespace std;

void print_chessboard(Chessboard cb, Coord begin, Coord end, List *l)
{
    ListNode *i=l->begin;
    int k=0;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((j+i)%2)
                cb[j][i]=(char)219;
            else cb[j][i]=' ';
        }
    }

    while(i)
    {
        cb[i->data[0]][i->data[1]]=k+'0';
        k++;
        i=i->next;
    }

    for(int i=0; i<8; i++)
    {
        cout<<i+1<<' ';
        for(int j=0; j<8; j++)
        {
            cout<<(char)cb[j][i];
        }
        cout<<endl;
    }

    cout<<endl<<"  ";
    for(int i=1; i<=8; i++)
        cout<<i;
}

void print_list(List *coord)
{
    ListNode *i=coord->begin;

    while(i)
    {
        cout<<'{'<<i->data[0]<<','<<i->data[1]<<"} ";
        i=i->next;
    }
}

int authorized_move[8][2]={ {-1, 2},
                            { 1, 2},
                            { 2, 1},
                            { 2,-1},
                            { 1,-2},
                            {-1,-2},
                            {-2,-1},
                            {-2, 1}};

int main()
{
    Coord begin, end;
    Chessboard cb={0};
    Queue *q=queue_init();
    Move move;
    bool steed_in_place=false;

    do
    {
        cout<<"Begin coord: ";
        cin>>begin[0]>>begin[1];
    }
    while(begin[0]>8 || begin[0]<1 || begin[1]>8 || begin[1]<1);

    do
    {
        cout<<"End coord: ";
        cin>>end[0]>>end[1];
    }
    while(end[0]>8 || end[0]<1 || end[1]>8 || end[1]<1);

    begin[0]--;
    begin[1]--;
    end[0]--;
    end[1]--;
    cb[begin[0]][begin[1]]=1;

    move.current_position[0]=begin[0];
    move.current_position[1]=begin[1];
    move.move=list_init();
    list_push(move.move, begin);
    queue_push(q, move);

    if(begin[0]==end[0] && begin[1]==end[1])
    {
        steed_in_place=true;

        cout<<endl;
        print_chessboard(cb, begin, end, move.move);
        list_free(move.move);
    }

    while(!steed_in_place)
    {
        move=queue_pop(q);
        List *list_tmp=move.move;

        move.move=list_init();
        list_copy(move.move, list_tmp);

        for(int i=0; i<8; i++)
        {
            begin[0]=move.current_position[0]+authorized_move[i][0];
            begin[1]=move.current_position[1]+authorized_move[i][1];

            if(begin[0]>=0 && begin[0]<8 && begin[1]>=0 && begin[1]<8 && !cb[begin[0]][begin[1]])
            {
                Move tmp_move;
                cb[begin[0]][begin[1]]=true;

                tmp_move.current_position[0]=begin[0];
                tmp_move.current_position[1]=begin[1];

                List *list_tmp=move.move;
                tmp_move.move=list_init();
                list_copy(tmp_move.move, list_tmp);
                list_push(tmp_move.move, begin);

                queue_push(q, tmp_move);

                if(begin[0]==end[0] && begin[1]==end[1])
                {
                    steed_in_place=true;

                    cout<<endl;
                    print_chessboard(cb, begin, end, tmp_move.move);
                    break;
                }
            }
        }
        list_free(move.move);
    }

    queue_free(q);
    getch();
    return 0;
}
