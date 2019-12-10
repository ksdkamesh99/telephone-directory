#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct newentry{
    char name[50];
    struct newentry *link;
    char phoneno[15];
    char email[50];
    char address[200];
    char pinno[6];
    char city[25];
    
}ne;
int isEmpty(ne *p){
    if(p==NULL){
        return 0;
    }
    return 1;
}
void Displayrow(ne *p,int i){
	printf("%d------%s------%s--------%s--------%s-------%s-------%s\n",i,p->name,p->phoneno,p->email,p->city,p->address,p->pinno);
	
}

ne *deletee(ne *p){
    printf("press 1 to delete entry by phone no (or) press 2 to delete  entry by email \n");
    int yy;
    ne *temp=NULL;
    temp=p;
    ne *temp1;
    scanf("%d",&yy);
    if(yy==1){
        printf("enter the phone no \n");
        char v[15];
        scanf("%s",v);
        if(strcmp(p->phoneno,v)==0){
            if(p->link==NULL){
                p=NULL;
                return p;
            }
            else{
                temp1=p->link;
                p->link=NULL;
                ne *q=p;
                p=temp1;
                free(q);
                return p;
            }
        }
        else{
            while(temp!=NULL){
                if(strcmp(temp->phoneno,v)==0){
                    temp1->link=temp->link;
                    temp->link=NULL;
                    free(temp);
                    return p;
                }
                temp1=temp;
                temp=temp->link;
            }
        }
    }
    else if(yy==2){
        printf("enter the email \n");
        char v[50];
        scanf("%s",v);
        if(strcmp(p->email,v)==0){
            if(p->link==NULL){
                p=NULL;
                return p;
            }
            else{
                temp1=p->link;
                p->link=NULL;
                ne *q=p;
                p=temp1;
                free(q);
                return p;
            }
        }
        else{
            while(temp!=NULL){
                if(strcmp(temp->email,v)==0){
                    temp1->link=temp->link;
                    temp->link=NULL;
                    free(temp);
                    return p;
                }
                temp1=temp;
                temp=temp->link;
            }
        }
    }
}
void display(ne *p){
    printf("enter the phone no of the entry to display the details\n");
    char d[15];
    scanf("%s",d);
    ne *temp=NULL;
    temp=p;
   static int v=0;
    while(temp!=NULL){
        int h;
        h=strcmp(temp->phoneno,d);
        if(h==0){
            v=1;
            break;
        }
        temp=temp->link;
    }
    if(v==1){
        printf("name of the entry is %s\n",temp->name);
        printf("phone no of the entry is %s\n",temp->phoneno);
        printf("email of the entry is %s\n",temp->email);
        printf("city of the entry is %s\n",temp->city);
        printf("address of the entry is %s\n",temp->address);
        printf("pin no of the entry is %s\n",temp->pinno);
    }
    else{
        printf("entry record not found\n");
    }
}

void entiredisplay(ne *p){
    ne *temp;
    temp=p;
    if(temp==NULL){
        printf("telephone directory is empty\n");
    }
    else{
        int i=0;
        while(temp!=NULL){
            i++;
			printf("S.No- %d",i);
            printf("name of the entry is %s\n",temp->name);
        	printf("phone no of the entry is %s\n",temp->phoneno);
        	printf("email of the entry is %s\n",temp->email);
        	printf("city of the entry is %s\n",temp->city);
        	printf("address of the entry is %s\n",temp->address);
        	printf("pin no of the entry is %s\n",temp->pinno);
            temp=temp->link;
            
        }
    }
}


ne *insert(ne *p,char *nm,char *phone,char *em,char *cit,char *addres,char *pin){
    ne *temp=NULL;
    ne *temp1=NULL,*temp2=NULL;
    temp1=(ne*) malloc(sizeof(ne));
    if(temp1==NULL){
        printf("sorry,no enough space \n");
    }
    strcpy(temp1->name,nm);
    strcpy(temp1->phoneno,phone);
    strcpy(temp1->email,em);
    strcpy(temp1->city,cit);
    strcpy(temp1->address,addres);
    strcpy(temp1->pinno,pin);

    temp=p;
    if(p==NULL){
        p=temp1;
        return p;
    }
    else{
        while(temp!=NULL){
            
            int k=strcmp(temp1->name,temp->name);
            if(k<=0){
                if(temp==p){
                    temp1->link=temp;
                    p=temp1;
                    return p;
                }
                else{
                    temp1->link=temp;
                    temp2->link=temp1;
                    return p;
                }
            }
            temp2=temp;
            temp=temp->link;
        }
        if(temp==NULL){
            temp2->link=temp1;
            return p;
        }
    }
    return p;
    
}

void search(ne *p){
    printf("press 1 to search entries based on name\n");
    printf("press 2 to search entries based on phone no\n");
    printf("press 3 to search entries based on email\n");
    printf("press 4 to search entries based on city name\n");
    printf("press 5 to search entries based on pin no\n");
    int yy;
    scanf("%d",&yy);
    ne *temp=NULL;
    temp=p;
    int w=isEmpty(p);
    if(!w){
        printf("empty telephone directory\n");
    }
    else{
        if(yy==1){
            printf("enter the name\n");
            char v[50];
            scanf("%s",v);
            int i=0;
            while(temp!=NULL){
                int u=strcmp(temp->name,v);
                if(u==0){
                     i++;
            printf("s-no: %d\n",i);
            printf("name of the entry is %s\n",temp->name);
            printf("phone no of the entry is %s\n",temp->phoneno);
            printf("email of the entry is %s\n",temp->email);
            printf("city of the entry is %s\n",temp->city);
            printf("address of the entry is %s\n",temp->address);
            printf("pin no of the entry is %s\n",temp->pinno);
            printf("\n\n");
                }
                temp=temp->link;
            }
            if(i==0){
                printf("entry record not found\n");
            }
        }
        else if(yy==2){
            printf("enter the phone no \n");
            char v[15];
            scanf("%s",v);
            int i=0;
            while(temp!=NULL){
                int u=strcmp(temp->phoneno,v);
                if(u==0){
                     i++;
            printf("s-no: %d\n",i);
            printf("name of the entry is %s\n",temp->name);
            printf("phone no of the entry is %s\n",temp->phoneno);
            printf("email of the entry is %s\n",temp->email);
            printf("city of the entry is %s\n",temp->city);
            printf("address of the entry is %s\n",temp->address);
            printf("pin no of the entry is %s\n",temp->pinno);
            printf("\n\n");
                }
                temp=temp->link;
            }
            if(i==0){
                printf("entry record not found\n");
            }
        }
        else if(yy==3){
            printf("enter the email\n");
            char v[50];
            scanf("%s",v);
            int i=0;
            while(temp!=NULL){
                int u=strcmp(temp->email,v);
                if(u==0){
                     i++;
            printf("s-no: %d\n",i);
            printf("name of the entry is %s\n",temp->name);
            printf("phone no of the entry is %s\n",temp->phoneno);
            printf("email of the entry is %s\n",temp->email);
            printf("city of the entry is %s\n",temp->city);
            printf("address of the entry is %s\n",temp->address);
            printf("pin no of the entry is %s\n",temp->pinno);
            printf("\n\n");
                }
                temp=temp->link;
            }
            if(i==0){
                printf("entry record not found\n");
            }
        }
        else if(yy==4){
            printf("enter the city name\n");
            char v[25];
            scanf("%s",v);
            int i=0;
            while(temp!=NULL){
                int u=strcmp(temp->city,v);
                if(u==0){
                     i++;
            printf("s-no: %d\n",i);
            printf("name of the entry is %s\n",temp->name);
            printf("phone no of the entry is %s\n",temp->phoneno);
            printf("email of the entry is %s\n",temp->email);
            printf("city of the entry is %s\n",temp->city);
            printf("address of the entry is %s\n",temp->address);
            printf("pin no of the entry is %s\n",temp->pinno);
            printf("\n\n");
                }
                temp=temp->link;
            }
            if(i==0){
                printf("entry record not found\n");
            }
        }
        else if(yy==5){
            printf("enter the pin no\n");
            char v[6];
            scanf("%s",v);
            int i=0;
            
            while(temp!=NULL){
                int u=strcmp(temp->pinno,v);
                if(u==0){
                     i++;
            printf("s-no: %d\n",i);
            printf("name of the entry is %s\n",temp->name);
            printf("phone no of the entry is %s\n",temp->phoneno);
            printf("email of the entry is %s\n",temp->email);
            printf("city of the entry is %s\n",temp->city);
            printf("address of the entry is %s\n",temp->address);
            printf("pin no of the entry is %s\n",temp->pinno);
            printf("\n\n");
                }
                temp=temp->link;
            }
            if(i==0){
                printf("entry record not found\n");
            }
        }
        else{
            printf("***INVALID CHOICE***\n---------tRY aGAIN---------\n");
        }
    }
    
}


ne* entireempty(ne *p){
    ne *temp=NULL,*temp1=NULL,*temp2=NULL;
    temp=p;
    while(temp!=NULL){
        temp1=temp;
        temp=temp->link;
        temp1->link=NULL;
        free(temp1);
    }
    return NULL;
}

int main() {
    char nm[50],em[50],addres[200];
    char pin[6],phone[15],cit[25];
    printf("------------------------------TELEPHONE DIRECTORY------------------------\n");
    printf("------------------------------Welcome------------------------------------\n");
    printf("=========================telephone directory operations==================\n");
    printf("press 1 for new entry in telephone directory\npress 2 for display of a entry in the telephone directory\npress 3 for deleting a entry in telephone directory\npress 4 for displaying the entire telephone directory\npress 5 to search a entry in telephone directory\npress 6 to empty the entire telephone directory\n");
    printf("press 7 for quit\n");
    ne *telephone=NULL;
    while(1){
        printf("enter your choice  ");
        int n;
        scanf("%d",&n);
        if(n==1){
            printf("\nenter the full name: ");
            scanf("%s",nm);
            printf("\nenter the phone no: ");
            scanf("%s",phone);
            printf("\nenter the email address: ");
            scanf("%s",em);
            printf("\nenter the city name: ");
            scanf("%s",cit);
            printf("\nenter the complete address: ");
            scanf("%s",addres);
            printf("\nenter the pin no: ");
            scanf("%s",pin);
            telephone=insert(telephone,nm,phone,em,cit,addres,pin);
	    printf("entry successfully entered\n");

            
        }
        else if(n==2){
            display(telephone);
        }
        else if(n==3){
            telephone=deletee(telephone);
			printf("entry successfully deleted\n");
        }
        else if(n==4){
            entiredisplay(telephone);
        }
        else if(n==5){
            search(telephone);
        }
        else if(n==6){
            if(!isEmpty(telephone)){
                printf("it is already empty\n");
            }
            else{
                telephone=entireempty(telephone);
		printf("telephone directory is successfully empty\ns");
            }
        }
        else if(n==7){
            printf("Thank you\n");
            break;
            
        }
        else{
            printf("***INVALID CHOICE***\n---------tRY aGAIN---------\n");
        }
    }
	return 0;
}
