#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
  int id;  /*数字*/
  char type;   /*トランプのマーク*/
  char label;  /*トランプでの表記(A,J,Q,K)*/
  int point;   /*点数*/
}Card;

void shufle(Card *card){
  int a, b;
  Card c;

  srand((unsigned int) time(NULL));
  a=rand()%52;
  b=rand()%52;

  c=*(card+a);
  *(card+a)=*(card+b);
  *(card+b)=c;
}

void Trump(Card *card){
  int i;
  for(i=0;i<13;i++){
    (card+i+0)->id=i+1;
    (card+i+13)->id=i+1;
    (card+i+26)->id=i+1;
    (card+i+39)->id=i+1;

    (card+i+0)->type='S';
    (card+i+13)->type='D';
    (card+i+26)->type='H';
    (card+i+39)->type='C';
  }
  for(i=0;i<52;i++){
    if((card+i)->id==1){
      (card+i)->label='A';
    }else if((card+i)->id==11){
      (card+i)->label='J';
    }else if((card+i)->id==12){
      (card+i)->label='Q';
    }else if((card+i)->id==13){
      (card+i)->label='K';
    }else{
      (card+i)->label=card[i].id;
    }
  }
  for(i=0;i<52;i++){
    if((card+i)->id==1){
      (card+i)->point=10;
    }else if((card+i)->id==11){
      (card+i)->point=10;
    }else if((card+i)->id==12){
      (card+i)->point=10;
    }else if((card+i)->id==13){
      (card+i)->point=10;
    }else{
      (card+i)->point=(card+i)->id;
    }
  }
}


void draw(Card *card, Card *a, int i, int j){
  /*山札からカードを引く*/
  a[i]=card[j];
}

void swap(Card *a, Card *b){
  Card c;
  c=*a;
  *a=*b;
  *b=c;
}

void Sort(Card *a, int i){
  /*トランプを数字の順番に並べる*/
  int j, k;
  Card *c;
  for(k=1;k<i;k++){
    for(j=0;j<i-1;j++){
      if(a[j].id>a[j+1].id){
        swap(&a[j],&a[j+1]);
      }
    }
  }
}

void Sorts(Card *s, int m, int v){
  /*トランプを数字の順番に並べる*/
  int j, k;
  for(k=1;k<m;k++){
    for(j=v;j<m;j++){
      if(s[j].id>s[j+1].id){
        swap(&s[j],&s[j+1]);
      }
    }
  }
}

void list(Card *card, int i){
  if(card[i].id==1){
    printf("[%c%c]",card[i].type,card[i].label);
  }else if(card[i].id==11){
    printf("[%c%c]",card[i].type,card[i].label);
  }else if(card[i].id==12){
      printf("[%c%c]",card[i].type,card[i].label);
  }else if(card[i].id==13){
    printf("[%c%c]",card[i].type,card[i].label);
  }else{
    printf("[%c%d]",card[i].type,card[i].label);
  }
}

void player(int f){
  if(f==1){
    printf("cpuB:");
  }else if(f==2){
    printf("cpuC:");
  }else if(f==3){
    printf("cpuD:");
  }else if(f==4){
    printf("あなた:");
  }
}

void sequenceokiba(Card *s, Card *t, int m, int n){
  int x, y;
  printf("シークエンス置き場:");
  for(x=0;x<m-1;x++){
    if(s[x].id==0){
      if(s[x].type=='A'){
	printf("{");
      }else if(s[x].type=='B'){
	printf("}");
      }
    }else{
      list(s,x);
    }
  }
  for(y=0;y<n-1;y++){
    if(t[y].id==0){
      if(t[y].type=='A'){
        printf("{");
      }else if(t[y].type=='B'){
        printf("}");
      }
    }else{
      list(t,y);
    }
  }
  printf("\n");
}

int remain(Card *a){
  int i;
  for(i=0;i<8;i++){
    if(a[i].id!=0){
      i=8-i;
      break;
    }else if(a[7].id==0){
      i=0;
      break;
    }
  }
  return i;
}
	
int sum(Card *a){
  int i, x=0;
  for(i=0;i<8;i++){
    x=x+a[i].point;
  }
  return x;
}

void rank(Card *a){
  int i=a[0].id, j=a[1].id, k=a[2].id, l=a[3].id;
  Sort(a,4);
  if(a[0].id==i){
    printf("1位:あなた %d点\n",i);
  }else if(a[0].id==j){
    printf("1位:cpuB %d点\n",j);
  }else if(a[0].id==k){
    printf("1位:cpuC %d点\n",k);
  }else if(a[0].id==l){
    printf("1位:cpuD %d点\n",l);
  }
  if(a[1].id==i){
    printf("2位:あなた %d点\n",i);
  }else if(a[1].id==j){
    printf("2位:cpuB %d点\n",j);
  }else if(a[1].id==k){
    printf("2位:cpuC %d点\n",k);
  }else if(a[1].id==l){
    printf("2位:cpuD %d点\n",l);
  }
  if(a[2].id==i){
    printf("3位:あなた %d点\n",i);
  }else if(a[2].id==j){
    printf("3位:cpuB %d点\n",j);
  }else if(a[2].id==k){
    printf("3位:cpuC %d点\n",k);
  }else if(a[2].id==l){
    printf("3位:cpuD %d点\n",l);
  }
  if(a[3].id==i){
    printf("4位:あなた %d点\n",i);
  }else if(a[3].id==j){
    printf("4位:cpuB %d点\n",j);
  }else if(a[3].id==k){
    printf("4位:cpuC %d点\n",k);
  }else if(a[3].id==l){
    printf("4位:cpuD %d点\n",l);
  }
}

void ThrowAway5(Card *a, Card*e, int l, int d){
  int u, k=1, q, x, y, i=7;
  player(d);
  printf("捨てる手札を選択してください\n");
  player(d);
  Sort(a,8);
  for(x=0;x<=i;x++){
    if(a[x].id!=0){
      y=x;
      break;
    }
  }
  for(u=0;u<=i;u++){
    if(a[u].id!=0){
      printf("%d:",k);
      list(a,u);
      k++;
    }
  }
  printf("\n");
  player(d);
  scanf("%d",&q);
  player(d);
  l=q+y-1;
  list(a,l);
  printf("を捨てました\n");
  a[l].id = 0;
  a[l].type ='E';
  a[l].point = 0;
}

void ThrowAway6(Card *a, Card*e, int l, int d){
  int i=7;
  Sort(a,i+1);
  e[l]=a[i];
  player(d);
  list(e,l);
  printf("を捨てました\n");
  a[i].id = 0;
  a[i].type ='E';
  a[i].point = 0;
  Sort(a,i+1);
}

void ThrowAway1(Card *card, Card *s, int k, int m, int d){
  /*連続する数字のカードが3枚以上もしくは同じ数字のカードを3枚以上出す*/
  int i, g, x=m, w, v=3, y;
  for(i=0;i<6;i++){
    if(card[i].id!=0){
      for(y=i+1;y<7;y++){
        if(card[i].id==card[y].id-1){
	  if(card[i].type==card[y].type){
            for(w=i+2;w<8;w++){
              if(card[y].id-1==card[w].id-2){
                if(card[w].type==card[y].type){
                  player(d);
                  m=m+2;
                  list(card,i);
                  list(card,y);
                  list(card,w);
                  for(g=w+1;g<8;g++){
                    if(card[i].id==card[g].id-v){
                      if(card[i].type==card[g].type){
                        s[x+v]=card[g];
                        list(card,g);
                        card[g].id=0;
                        card[g].type='E';
			card[g].point=0;
                        v++;
                        m++;
                      }
                    }
                  }
                  printf("をシークエンス置き場に出しました\n");
                  s[x]=card[i];
		  card[i].id=0;
                  card[i].type='E';
		  card[i].point=0;
                  s[x+1]=card[y];
                  card[y].id=0;
                  card[y].type='E';
		  card[y].point=0;
                  s[x+2]=card[w];
                  card[w].id=0;
                  card[w].type='E';
		  card[w].point=0;
                  m++;
                  s[m].id=0;
                  s[m].type='B';
                  m++;
                  s[m]=s[0];
                  m++;
                  s[m].type='F';
                }
              }
            }
          }
        }
      }
    }
  }
}

void ThrowAway2(Card *card, Card *t, int k, int n, int d){
  /*連続する数字のカードが3枚以上もしくは同じ数字のカードを3枚以上出す*/
  int i, g, w, v=3, y, z=n;
  for(i=0;i<6;i++){
    if(card[i].id!=0){
      for(y=i+1;y<7;y++){
        if(card[i].id==card[y].id){
          for(w=y+1;w<8;w++){
            if(card[i].id!=0){
	      if(card[i].id==card[w].id){
                player(d);
                n=n+2;
                list(card,i);
                list(card,y);
                list(card,w);
                for(g=w+1;g<8;g++){
                  if(card[w].id==card[g].id){
                    t[z+3]=card[g];
                    list(card,g);
                    card[g].id=0;
                    card[g].type='E';
		    card[g].point=0;
                    n++;
                  }
                }
                printf("をシークエンス置き場に出しました\n");
                t[z]=card[i];
                card[i].id=0;
                card[i].type='E';
		card[i].point=0;
                t[z+1]=card[y];
                card[y].id=0;
                card[y].type='E';
		card[y].point=0;
                t[z+2]=card[w];
                card[w].id=0;
                card[w].type='E';
		card[w].point=0;
                n++;
                t[n].id=0;
                t[n].type='B';
                n++;
                t[n]=t[0];
                n++;
		t[n].type='F';
              }
            }
          }
        }
      }
    }
  }
}

void ThrowAway3(Card *card, Card *s, int k, int m, int d){
  /*連続する数字のカードが3枚以上もしくは同じ数字のカードを3枚以上出す*/
  int i, g, w, v=3, y, q;
  for(i=0;i<6;i++){
    if(card[i].id!=0){
      for(y=i+1;y<7;y++){
        if(card[i].id==card[y].id-1){
          if(card[i].type==card[y].type){
            for(w=y+1;w<8;w++){
              if(card[y].id-1==card[w].id-2){
                if(card[w].type==card[y].type){
                  player(d);
                  list(card,i);
                  list(card,y);
                  list(card,w);
                  for(g=w+1;g<8;g++){
                    if(card[i].id==card[g].id-v){
                      if(card[i].type==card[g].type){
                        list(card,g);
                        v++;
                      }
                    }
                  }
                  printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
		  player(d);
                  scanf("%d",&q);
                  if(q==1){
                    ThrowAway1(card,s,k,m,d);
                  }else if(q==2){
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void ThrowAway4(Card *card, Card *t, int k, int n, int d){
  /*連続する数字のカードが3枚以上もしくは同じ数字のカードを3枚以上出す*/
  int i, g, w, v=3, y, q;
  for(i=0;i<6;i++){
    if(card[i].id!=0){
      for(y=i+1;y<7;y++){
        if(card[i].id==card[y].id){
          for(w=y+1;w<8;w++){
            if(card[i].id==card[w].id){
              player(d);
              list(card,i);
              list(card,y);
              list(card,w);
              for(g=w+1;g<8;g++){
                if(card[i].id==card[g].id){
                  list(card,g);
                }
              }
	      printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
              player(d);
              scanf("%d",&q);
              if(q==1){
                ThrowAway2(card,t,k,n,d);
              }
            }
          }
        }
      }
    }
  }
}

void seven1(Card *a, Card *s, int i, int m, int d){
  int x, y, z=1, w=1, v=m, u;
  for(x=0;x<i;x++){
    if(a[x].id==7){
      s[m]=a[x];
      Sorts(s,m,v);
      a[x].id=0;
      a[x].type='E';
      a[x].point=0;
      m++;
      player(d);
      for(u=v;u<m;u++){
        list(s,u);
      }
      s[m].id=0;
      s[m].type='B';
      m++;
      s[m]=s[0];
      m++;
      s[m].type='F';
      printf("をシークエンス置き場に出しました\n");
    }
  }
}

void seven2(Card *a, Card *s, int i, int m, int d){
  int x, y, z=1, w=1, v, u, q, r=0, g;
  Card h[52];
  v=m;
  for(x=0;x<i;x++){
    if(a[x].id==7){
      player(d);
      list(a,x);
      printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
      player(d);
      scanf("%d",&q);
      if(q==1){
        seven1(a,s,i,m,d);
      }
    }
  }
}

int decrease1(Card *card, Card *t, int n, int d){
  /*カードをシークエンス置き場のと合わせて捨てる*/
  int i, x, y, z;
  for(i=0;i<8;i++){
    for(x=0;x<n;x++){
      if(card[i].id!=0){
	if(card[i].id==t[x].id){
	  y=x;
	  for(z=n;z>=y;z--){
	    t[z+1]=t[z];
	  }
	  t[y]=card[i];
	  card[i].id=0;
	  card[i].type='E';
	  card[i].point=0;
	  player(d);
	  list(t,y);
	  printf("をシークエンス置き場に出しました\n");
	goto end;
	}
      }
    }
  }
 end:
  return 0;
}

int decrease2(Card *card, Card *s, int m, int d){
  /*カードをシークエンス置き場のと合わせて捨てる*/
  int i, x, y, z;
  for(i=0;i<8;i++){
    for(x=0;x<m;x++){
      if(card[i].id!=0){
        if(card[i].id==s[x].id-1){
	  if(card[i].type==s[x].type){
	    for(z=m;z>=x;z--){
	      s[z+1]=s[z];
	    }
	    s[x]=card[i];
	    card[i].id=0;
	    card[i].type='E';
	    card[i].point=0;
	    player(d);
	    list(s,x);
	    printf("をシークエンス置き場に出しました\n");
	    goto end;
	  }
	}else if(card[i].id==s[x].id+1){
	  if(card[i].type==s[x].type){
	    y=x+1;
	    for(z=m;z>x;z--){
	      s[z+1]=s[z];
	    }
	    s[y]=card[i];
	    card[i].id=0;
	    card[i].type='E';
	    card[i].point=0;
	    player(d);
	    list(s,y);
            printf("をシークエンス置き場に出しました\n");
	    goto end;
	  }
	}
      }
    }
  }
 end:
  return 0;
}

int decrease3(Card *card, Card *t, int n, int d){
  /*カードをシークエンス置き場のと合わせて捨てる*/
  int i, x, y, z, q;
  for(i=0;i<8;i++){
    for(x=0;x<n;x++){
      if(card[i].id!=0){
        if(card[i].id==t[x].id){
	  player(d);
          list(card,i);
	  printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
	  player(d);
	  scanf("%d",&q);
	  if(q==1){
	    decrease1(card,t,n,d);
	    goto end;
	  }else if(q==2){
	    break;
	  }
	}
      }
    }
  }
 end:
  return 0;
}

int decrease4(Card *card, Card *s, int m, int d){
  /*カードをシークエンス置き場のと合わせて捨てる*/
  int i, x, y, z, q;
  for(i=0;i<8;i++){
    for(x=0;x<m;x++){
      if(card[i].id!=0){
        if(card[i].id==s[x].id-1){
          if(card[i].type==s[x].type){
	    player(d);
	    list(card,i);
	    printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
	    player(d);
	    scanf("%d",&q);
	    if(q==1){
	      decrease2(card,s,m,d);
	      goto end;
	    }else if(q==2){
	      break;
	    }
	  }
        }else if(card[i].id==s[x].id+1){
          if(card[i].type==s[x].type){
            player(d);
	    list(card,i);
	    printf("をシークエンス置き場に出しますか?1:はい 2:いいえ\n");
	    player(d);
	    scanf("%d",&q);

	    if(q==1){
	      decrease2(card,s,m,d);
	      goto end;
	    }else if(q==2){
	      break;
	    }
	  }
        }
      }
    }
  }
 end:
  return 0;
}

void Pon1(Card *card, Card *a, Card *t, int j, int k, int n, int f){
  /*ポンの時の関数*/
  int i, u, v, y;
  for(i=0;i<j;i++){
    if(card[i].id!=0){
      if(card[i].id==a[k-1].id){
	if(card[i+1].id==a[k-1].id){
	  t[n]=card[i];
	  t[n+1]=card[i+1];
	  t[n+2]=a[k-1];
	  v=n+2;
	  player(f);
	  card[i].id=0;
	  card[i].type='E';
	  card[i].point=0;
	  card[i+1].id=0;
	  card[i+1].type='E';
	  card[i+1].point=0;
	  a[k-1].id=0;
	  a[k-1].type='G';
	  for(u=n;u<=v;u++){
	    list(t,u);
	  }
	  t[u].id=0;
	  t[u].type='B';
	  u++;
	  t[u]=t[0];
	  u++;
	  t[u].id=0;
	  t[u].type='F';
	  printf("でポンしました\n");
	  break;
	}
      }
    }
  }
}

void Pon2(Card *card, Card *a, Card *t, int j, int k, int n, int f){
  /*ポンの時の関数*/
  int i, u, v, z;
  for(i=0;i<j;i++){
    if(card[i].id!=0){
      if(card[i].id==a[k-1].id){
	if(card[i+1].id==a[k-1].id){
	  player(f);
	  list(card,i);
	  list(card,i+1);
	  list(a,k-1);
	  printf("でポンしますか？1:はい 2:いいえ\n");
	  player(f);
	  scanf("%d",&z);
	  if(z==1){
	    Pon1(card,a,t,j,k,n,f);
	  }
	  break;
	}
      }
    }
  }
}

void Qi1(Card *card, Card *a, Card *s, int k, int m, int d){
  /*チーの時の関数*/
  int i, l=0, g, h=2, x=3,y, z=2, v=3,w, r, o=3, p, q, f=1;
  for(i=0;i<8;i++){
    if(card[i].id==a[k-1].id-1){
      if(card[i].type==a[k-1].type){
        for(y=i-1;y>=0;y--){
          if(card[y].id==a[k-1].id-2){
            if(card[y].type==a[k-1].type){
              player(d);
              s[m]=card[y];
              list(s,m);
              card[y].id=0;
              card[y].type='E';
              card[y].point=0;
              m++;
              s[m]=card[i];
              list(s,m);
              card[i].id=0;
              card[i].type='E';
              card[i].point=0;
              m++;
              s[m]=a[k-1];
              list(s,m);
              a[k-1].id=0;
              a[k-1].type='G';
              m++;
	      printf("でチーしました\n");
              s[m].id=0;
              s[m].type='B';
              m++;
              s[m]=s[0];
              m++;
              s[m].type='F';
            }
          }
        }
        for(y=i+1;y<8;y++){
          if(card[y].id==a[k-1].id+1){
            if(card[y].type==a[k-1].type){
              player(d);
              s[m]=card[i];
              list(s,m);
              card[i].id=0;
              card[i].type='E';
              card[i].point=0;
              m++;
              s[m]=a[k-1];
              list(s,m);
              a[k-1].id=0;
              a[k-1].type='G';
              m++;
              s[m]=card[y];
              list(s,m);
              card[y].id=0;
              card[y].type='E';
              card[y].point=0;
              m++;
              printf("でチーしました\n");
              s[m].id=0;
              s[m].type='B';
              m++;
              s[m]=s[0];
              m++;
              s[m].type='F';
            }
          }
        }
      }
    }else if(card[i].id==a[k-1].id+1){
      if(card[i].type==a[k-1].type){
	for(y=i+1;y<8;y++){
	  if(card[y].id==a[k-1].id+2){
	    if(card[y].type==a[k-1].type){
	      player(d);
	      s[m]=a[k-1];
	      list(s,m);
	      a[k-1].id=0;
	      a[k-1].type='G';
	      m++;
	      s[m]=card[i];
	      list(s,m);
	      card[i].id=0;
	      card[i].type='E';
	      card[i].point=0;
	      m++;
	      s[m]=card[y];
	      list(s,m);
	      card[y].id=0;
	      card[y].type='E';
	      card[y].point=0;
	      m++;
	      printf("でチーしました\n");
	      s[m].id=0;
	      s[m].type='B';
	      m++;
	      s[m]=s[0];
	      m++;
	      s[m].type='F';
	    }
	  }
	}
      }
    }
  }
}

void Qi2(Card *card, Card *a, Card *s, int k, int m, int d){
  /*チーの時の関数*/
  int i, l=0, g, h=2, x=3,y, z=2, v=3,w, r, o=3, p, q, f=1;
  for(i=0;i<8;i++){
    if(card[i].id==a[k-1].id-1){
      if(card[i].type==a[k-1].type){
	for(y=i-1;y>=0;y--){
          if(card[y].id==a[k-1].id-2){
            if(card[y].type==a[k-1].type){
              player(d);
              list(card,y);
              list(card,i);
              list(a,k-1);
              printf("でチーしますか?1:はい 2:いいえ\n");
              player(d);
              scanf("%d",&q);
              if(q==1){
                Qi1(card,a,s,k,m,d);
              }
            }
          }
        }
        for(y=i+1;y<8;y++){
          if(card[y].id==a[k-1].id+1){
            if(card[y].type==a[k-1].type){
              player(d);
              list(card,i);
              list(a,k-1);
              list(card,y);
              printf("でチーしますか?1:はい 2:いいえ\n");
              player(d);
              scanf("%d",&q);
              if(q==1){
                Qi1(card,a,s,k,m,d);
              }
            }
          }
        }
      }
    }else if(card[i].id==a[k-1].id+1){
      if(card[i].type==a[k-1].type){
        for(y=i+1;y<8;y++){
          if(card[y].id==a[k-1].id+2){
            if(card[y].type==a[k-1].type){
              player(d);
              list(a,k-1);
              list(card,i);
              list(card,y);
              printf("でチーしますか?1:はい 2:いいえ\n");
	      player(d);
              scanf("%d",&q);
              if(q==1){
                Qi1(card,a,s,k,m,d);
              }
            }
          }
        }
      }
    }
  }
}

int main(){
  int i=1, j, k, l=0, m=0, n=0, o=0, f=1,x, y, z, g, as=0, bs=0, cs=0, ds=0, sa, sb, sc, sd ;/*oは順番*/
  Card trump[52];
  Card a[7], b[7], c[7], d[7], e[52];/*eは捨てたカードの値*/
  Card s[52], t[52];/*シークエンス用*/
  Card C[4];
  Trump(trump);
  shufle(trump);
  for(j=0;j<28;j=j+4){
    a[i]=trump[j];
    b[i]=trump[j+1];
    c[i]=trump[j+2];
    d[i]=trump[j+3];
    i++;
  }
  s[0].id=0;
  s[0].type='A';
  t[0].id=0;
  t[0].type='A';
  n=1;
  m=1;
  draw(trump,a,0,j);
  j++;
  Sort(a,8);
  printf("ゲームを開始します\n");
  for(z=28;z<52;z++){
    if(f==1){
      draw(trump,b,0,j);
      j++;
      Sort(b,8);
      ThrowAway1(b,s,l,m,1);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	bs=1;
      }
      Sort(b,8);
      ThrowAway2(b,t,l,n,1);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	bs=1;
      }
      Sort(b,8);
      seven1(b,s,8,m,1);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	bs=1;
      }
      Sort(b,8);
      if(bs==1){
	decrease1(b,t,n,1);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(b,8);
	decrease2(b,s,m,1);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(b,8);
      ThrowAway6(b,e,l,1);
      l++;
      Sort(b,8);
      g=remain(b);
      player(1);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(c,e,t,8,l,n,2);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	cs=1;
	f=6;
      }else{
	Pon1(d,e,t,8,l,n,3);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  ds=1;
	  f=7;
	}else{
	  Pon2(a,e,t,8,l,n,4);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    as=1;
	    f=8;
	  }else{
	    y=m;
	    Qi1(c,e,s,l,m,2);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      cs=1;
	      f=6;
	    }
	    f++;
	  }
	}
      }
    }
    
    if(f==2){
      draw(trump,c,0,j);
      j++;
      Sort(c,8);
      ThrowAway1(c,s,l,m,2);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	cs=1;
      }
      Sort(c,8);
      ThrowAway2(c,t,l,n,2);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	cs=1;
      }
      Sort(c,8);
      seven1(c,s,8,m,2);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	cs=1;
      }
      Sort(c,8);
      if(cs==1){
	decrease1(c,t,n,2);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(c,8);
	decrease2(c,s,m,2);
	for(x=n;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(c,8);
      ThrowAway6(c,e,l,2);
      l++;
      Sort(c,8);
      g=remain(c);
      player(2);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(d,e,t,8,l,n,3);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	ds=1;
	f=7;
      }else{
	Pon2(a,e,t,8,l,n,4);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  as=1;
	  f=8;
	}else{
	  Pon1(b,e,t,8,l,n,1);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    bs=1;
	    f=5;
	  }else{
	    y=m;
	    Qi1(d,e,s,l,m,3);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      ds=1;
	      f=7;
	    }
	    f++;
	  }
	}
      }
    }

    if(f==3){
      draw(trump,d,0,j);
      j++;
      Sort(d,8);
      ThrowAway1(d,s,l,m,3);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	ds=1;
      }
      Sort(d,8);
      ThrowAway2(d,t,l,n,3);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	ds=1;
      }
      Sort(d,8);
      seven1(d,s,8,m,3);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	ds=1;
      }
      Sort(d,8);
      if(ds==1){
	decrease1(d,t,n,3);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(d,8);
	decrease2(d,s,m,3);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(d,8);
      ThrowAway6(d,e,l,3);
      l++;
      Sort(d,8);
      g=remain(d);
      player(3);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon2(a,e,t,8,l,n,4);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	as=1;
	f=8;
      }else{
	Pon1(b,e,t,8,l,n,1);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  bs=1;
	  f=5;
	}else{
	  Pon1(c,e,t,8,l,n,2);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    cs=1;
	    f=6;
	  }else{
	    y=m;
	    Qi2(a,e,s,l,m,4);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      as=1;
	      f=8;
	    }
	    f++;
	  }
	}
      }
    }


    if(f==4){
      draw(trump,a,0,j);
      j++;
      Sort(a,8);
      sequenceokiba(s,t,m,n);
      ThrowAway3(a,s,l,m,4);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	as=1;
      }
      ThrowAway4(a,t,l,n,4);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	as=1;
      }
      seven2(a,s,8,m,4);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	as=1;
      }
      if(as==1){
	decrease3(a,t,n,4);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(a,8);
	decrease4(a,s,m,4);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(a,8);
      ThrowAway5(a,e,l,4);
      l++;
      Sort(a,8);
      g=remain(a);
      player(4);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(b,e,t,8,l,n,1);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	bs=1;
	f=5;
      }else{
	Pon1(c,e,t,8,l,n,2);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  cs=1;
	  f=6;
	}else{
	  Pon1(d,e,t,8,l,n,3);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    ds=1;
	    f=7;
	  }else{
	    y=m;
	    Qi1(b,e,s,l,m,1);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      bs=1;
	      f=5;
	    }
	    f=1;
	  }
	}
      }
    }
 		
    if(f==5){
      Sort(b,8);
      ThrowAway1(b,s,l,m,1);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	bs=1;
      }
      Sort(b,8);
      ThrowAway2(b,t,l,n,1);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	bs=1;
      }
      Sort(b,8);
      seven1(b,s,8,m,1);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	bs=1;
      }
      Sort(b,8);
      if(bs==1){
	decrease1(b,t,n,1);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(b,8);
	decrease2(b,s,m,1);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(b,8);
      ThrowAway6(b,e,l,1);
      l++;
      Sort(b,8);
      g=remain(b);
      player(1);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(c,e,t,8,l,n,2);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	cs=1;
	f=6;
      }else{
	Pon1(d,e,t,8,l,n,3);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  ds=1;
	  f=7;
	}else{
	  Pon2(a,e,t,8,l,n,4);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    as=1;
	    f=8;
	  }else{
	    y=m;
	    Qi1(c,e,s,l,m,2);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      cs=1;
	      f=6;
	    }
	    f=2;
	  }
	}
      }
    }

    if(f==6){
      Sort(c,8);
      ThrowAway1(c,s,l,m,2);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	cs=1;
      }
      Sort(c,8);
      ThrowAway2(c,t,l,n,2);
      y=n;
      for(x=n;x<52;x++){	    
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	cs=1;
      }
      Sort(c,8);
      seven1(c,s,8,m,2);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	cs=1;
      }
      Sort(c,8);
      if(cs==1){
	decrease1(c,t,n,2);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(c,8);
	decrease2(c,s,m,2);
	for(x=n;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(c,8);
      ThrowAway6(c,e,l,2);
      l++;
      Sort(c,8);
      g=remain(c);
      player(2);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(d,e,t,8,l,n,3);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	ds=1;
	f=7;
      }else{
	Pon2(a,e,t,8,l,n,4);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  as=1;
	  f=8;
	}else{
	  Pon1(b,e,t,8,l,n,1);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    bs=1;
	    f=5;
	  }else{
	    y=m;
	    Qi1(d,e,s,l,m,3);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      ds=1;
	      f=7;
	    }
	    f=3;
	  }
	}
      }
    }
    
    if(f==7){
      Sort(d,8);
      ThrowAway1(d,s,l,m,3);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	ds=1;
      }
      Sort(d,8);
      ThrowAway2(d,t,l,n,3);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	ds=1;
      }
      Sort(d,8);
      seven1(d,s,8,m,3);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	ds=1;
      }
      Sort(d,8);
      if(ds==1){
	decrease1(d,t,n,3);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(d,8);
	decrease2(d,s,m,3);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(d,8);
      ThrowAway6(d,e,l,3);
      l++;
      Sort(d,8);
      g=remain(d);
      player(3);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon2(a,e,t,8,l,n,4);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	as=1;
	f=8;
      }else{
	Pon1(b,e,t,8,l,n,1);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  bs=1;
	  f=5;
	}else{
	  Pon1(c,e,t,8,l,n,2);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    cs=1;
	    f=6;
	  }else{
	    y=m;
	    Qi2(a,e,s,l,m,4);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      as=1;
	      f=8;
	    }
	    f=4;
	  }
	}
      }
    }
    
    
    if(f==8){
      Sort(a,8);
      sequenceokiba(s,t,m,n);
      ThrowAway3(a,s,l,m,4);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	as=1;
      }
      ThrowAway4(a,t,l,n,4);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	as=1;
      }
      seven2(a,s,8,m,4);
      y=m;
      for(x=m;x<52;x++){
	if(s[x].type=='F'){
	  m=x;
	}
      }
      if(y!=m){
	as=1;
      }
      if(as==1){
	decrease3(a,t,n,4);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	Sort(a,8);
	decrease4(a,s,m,4);
	for(x=m;x<52;x++){
	  if(s[x].type=='F'){
	    m=x;
	  }
	}
      }
      Sort(a,8);
      ThrowAway5(a,e,l,4);
      l++;
      Sort(a,8);
      g=remain(a);
      player(4);
      printf("手札残り%d枚\n",g);
      if(g==0){
	break;
      }
      if(j==52){
	break;
      }
      Pon1(b,e,t,8,l,n,1);
      y=n;
      for(x=n;x<52;x++){
	if(t[x].type=='F'){
	  n=x;
	}
      }
      if(y!=n){
	l=l-1;
	bs=1;
	f=5;
      }else{
	Pon1(c,e,t,8,l,n,2);
	for(x=n;x<52;x++){
	  if(t[x].type=='F'){
	    n=x;
	  }
	}
	if(y!=n){
	  l=l-1;
	  cs=1;
	  f=6;
	  break;
	}else{
	  Pon1(d,e,t,8,l,n,3);
	  for(x=n;x<52;x++){
	    if(t[x].type=='F'){
	      n=x;
	    }
	  }
	  if(y!=n){
	    l=l-1;
	    ds=1;
	    f=7;
	  }else{
	    y=m;
	    Qi1(b,e,s,l,m,1);
	    for(x=m;x<52;x++){
	      if(s[x].type=='F'){
		m=x;
	      }
	    }
	    if(y!=m){
	      l=l-1;
	      bs=1;
	      f=5;
	    }
	    f=1;
	  }
	}
      }
    }
  }
  sa=sum(a);
  sb=sum(b);
  sc=sum(c);
  sd=sum(d);
  C[0].id=sa;
  C[1].id=sb;
  C[2].id=sc;
  C[3].id=sd;
  rank(C);


  return 0;
}
