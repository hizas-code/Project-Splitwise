#include "multilist.h"

//Functionality
void create_list(listinduk &L)
{
    first(L) = NULL;
}
void create_list_anak(listanak &L)
{
    first(L) = NULL;
    last(L) = NULL;
}
bool list_empty(listinduk L)
{
    return first(L) == NULL;
}
bool list_empty_anak(listanak L)
{
    return first(L) == NULL;
}
//Allocate
address alokasi_induk(infotypeinduk X)
{
    address P = new element_induk;
    info(P) = X;
    P->lanak.first = NULL;
    P->lanak.last = NULL;
    next(P) = NULL;
    return P;
}
address_anak alokasi_anak(infotypeanak X)
{
    address_anak Q=new element_anak;
    info(Q) = X;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
//Find
address find_element(listinduk L, infotypeinduk X)
{   if(L.first == NULL)
        return NULL;
    else
    {   address p = L.first;
        while(p != NULL)
        {   if(p->info.id == X.id)
                return p;
            else
                p = p->next;
        }
    }
    return NULL;
}
address_anak find_element_anak(listanak L, infotypeanak X)
{
    address_anak Q;
    if(not list_empty_anak(L))
    {
        Q=first(L);
        while(Q!= NULL)
        {
            if(info(Q).id==X.id)
            {
                return Q;
            }
            else
                Q=next(Q);
        }
    }
    return NULL;
}
//Input Data
void input_data_group(infotypeinduk &X)
{
    cout<<"Input Group Data"<<endl;
    cout<<"1. Group ID      : "; cin>>X.id;
    cout<<"2. Group Name    : "; cin>>X.nama;
    cout<<"3. Date Created  : "; cin>>X.tanggal;
    cout<<endl;
}
void input_data_member(infotypeanak &X)
{   cout<<"Input Member Data"<<endl
        <<"Member ID   : "; cin>>X.id;
    cout<<"Member Name : "; cin>>X.nama;
    cout<<"Email       : "; cin>>X.email;
    cout<<endl;
}

//Menu Based Order
//1. Add Group
void insert_group(listinduk &L)
{
    //Variable
    address P;
    infotypeinduk X;
    char choose;
    //Main
    cout<<"Add Group Menu"<<endl<<endl;
    input_data_group(X);
    address F = find_element(L,X);
    if(F != NULL)
    {
        cout<<endl<<"Group ID Inputted is already used! :("<<endl;
    }
    else
    {
        P = alokasi_induk(X);
        cout<<endl<<"Add Group to Group List with : "<<endl;
        cout<<"1. Insert First Group"<<endl
            <<"2. Insert Last Group"<<endl
            <<"3. Insert After Group"<<endl
            <<"0. Cancel Add Group"<<endl<<endl
            <<"Choose : "; cin>>choose;
        switch(choose)
        {
            case '1'    :
                insert_first(L,P);
                break;
            case '2'    :
                insert_last(L,P);
                break;
            case '3'    :
                insert_after(L,P);
                break;
            default     :
                cout<<endl<<"Add Group Cancelled!";
                delete P;
                break;
        }
    }
    getch();
}

void insert_first(listinduk &L, address P)
{
    next(P) = first(L);
    first(L) = P;
    cout<<endl<<"Add Group Success!";
}

void insert_last(listinduk &L, address P)
{
    if(list_empty(L))
    {
        first(L) = P;
    }
    else
    {
        address Q = first(L);
        while(next(Q) != NULL) Q = next(Q);
        next(Q) = P;
    }
    cout<<endl<<"Add Group Success!";
}

void insert_after(listinduk &L, address P)
{
    infotypeinduk X;
    address current;
    cout<<endl<<"Insert Group After Group's ID : ";
    cin>>X.id;
    current = find_element(L,X);
    if(current != Nil)
    {
        if(next(current) == Nil) next(current) = P; //Insert Last
        else
        {
            next(P) = next(current);
            next(current) = P;
        }
        cout<<endl<<"Add Group Success!";
    }
    else cout<<endl<<"ID Not Found, Add Group Failed!";
}

//2. Add Member
void insert_member(listinduk &L)
{
    //Variable
    char choose;
    infotypeinduk X;
    infotypeanak x;
    address adr;
    address_anak p;
    //Process
    cout<<"Add Member Menu"<<endl<<endl;
    input_data_member(x);
    p = alokasi_anak(x);
    cout<<"Add to Group (Input ID) : ";
    cin>>X.id; cout<<endl;
    adr = find_element(L,X);
    address_anak F = find_element_anak(adr->lanak,x);
    if(F != NULL)
        cout<<endl<<"Member ID Inputted is Already Used :("<<endl;
    else{
    if(adr == NULL)
        cout<<"Group's ID not found, Add Member Failed!"<<endl;
    else
    {   cout<<"Add Member to Group "<<adr->info.nama<<" with : "<<endl
            <<"1. Insert First"<<endl
            <<"2. Insert Last"<<endl
            <<"3. Insert After"<<endl
            <<"0. Cancel Add Member"<<endl<<endl
            <<"Choose : ";
        cin>>choose;
        switch(choose)
        {   case '1' : insert_first_anak(adr->lanak,p); break;
            case '2' : insert_last_anak(adr->lanak,p); break;
            case '3' : insert_after_anak(adr->lanak,p); break;
            default  : cout<<endl<<"Add Member Cancelled!"; break;
        }
    }}
    getch();
}

void insert_first_anak(listanak &L, address_anak Q)
{
    if(list_empty_anak(L))
    {
        first(L) = Q ;
        last(L) = Q;
    }
    else
    {
        next(Q) = first(L);
        prev(first(L)) = Q;
        first(L) = Q;
    }
    cout<<endl<<"Add Member Success!";
}

void insert_last_anak(listanak &L, address_anak p)
{
    if(L.first == NULL)
    {
        L.first = p;
        L.last = p;
    }
    else
    {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
    cout<<endl<<"Add Member Success!";
}

void insert_after_anak(listanak &L, address_anak Q)
{
    address_anak prec;
    infotypeanak b;
    cout<<"Insert Member After Member's ID : "; cin>>b.id;
    prec = find_element_anak(L,b);
    if(prec == NULL)
    {
        cout<<"ID Not Found, Add Member Failed!"<<endl;
    }
    else
    {
        if(prec == last(L))
        {
            insert_last_anak(L,Q);
        }
        else
        {
            next(Q) = next(prec);
            next(prec) = Q;
            prev(next(Q)) = Q;
            prev(Q) = prec;
            cout<<endl<<"Add Member Success!";
        }
    }
}

//3. Delete Group
void delete_group(listinduk &L)
{
    //Variable
    char choose;
    //Process
    cout<<"Delete Group Menu"<<endl<<endl
        <<"1. Delete First Group"<<endl
        <<"2. Delete Last Group"<<endl
        <<"3. Delete After Group"<<endl
        <<"0. Cancel Delete Group"<<endl<<endl
        <<"Choose : "; cin>>choose;
    cout<<endl;
    switch(choose)
    {
        case '1' :
            delete_first(L);
            break;
        case '2' :
            delete_after(L);
            break;
        case '3' :
            delete_last(L);
            break;
        default  :
            cout<<"Delete Group Cancelled!";
            break;
    }
    getch();
}

void delete_first(listinduk &L)
{
    address P;
    if(not list_empty(L))
    {
        P = first(L);
        if(next(first(L)) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
        }
        next(P) = NULL;
        cout<<"Delete Group Success!"<<endl<<endl
            <<"Group Deleted"<<endl
            <<"Group ID     : "<<info(P).id<<endl
            <<"Group Name   : "<<info(P).nama<<endl
            <<"Date Created : "<<info(P).tanggal<<endl;
        delete P;
    }
    else
    {
        cout<<"Group List is Empty, Nothing to Delete!";
    }
}

void delete_last(listinduk &L)
{
    if(not list_empty(L))
    {
        address Q = first(L);
        address P = first(L);
        if(next(first(L))==NULL)
        {
            first(L) = NULL;
        }
        else
        {
            while(next(next(P)) != Nil)
            {
                P = next(P);
            }
            Q = next(P);
            next(P) = Nil;
        }
        cout<<"Delete Group Success!"<<endl<<endl
            <<"Group Deleted"<<endl
            <<"Group ID     : "<<info(Q).id<<endl
            <<"Group Name   : "<<info(Q).nama<<endl
            <<"Date Created : "<<info(Q).tanggal<<endl;
        delete Q;
    }
    else
    {
        cout<<"Group List is Empty, Nothing to Delete!";
    }
}

void delete_after(listinduk &L)
{
    infotypeinduk X;
    address p;
    cout<<"Delete Group After Group's ID : "; cin>>X.id;
    p = find_element(L,X);
    if(p != NULL)
    {
        if(p->next != NULL)
        {
            address q = p->next;
            p->next = q->next;
            q->next = NULL;
            cout<<"Delete Group Success!"<<endl<<endl
            <<"Group Deleted"<<endl
            <<"Group ID     : "<<info(q).id<<endl
            <<"Group Name   : "<<info(q).nama<<endl
            <<"Date Created : "<<info(q).tanggal<<endl;
            delete q;
        }
        else cout<<"Group After that ID is Empty, Delete Group Failed!"<<endl;

    }
    else cout<<"ID Not Found, Delete Group Failed!"<<endl;
}

//4. Delete Member
void delete_member(listinduk &L)
{   //Variable
    char choose;
    infotypeinduk X;
    infotypeanak x;
    address adr;
    //Process
    cout<<"Delete Member Menu"<<endl<<endl
        <<"Delete Member of Group (Input ID) : ";
    cin>>X.id; cout<<endl;
    adr = find_element(L,X);
    if(adr == NULL) cout<<"Group's ID not found, Delete Member Cancelled!";
    else
    {   cout<<"Delete Member of Group "<<adr->info.nama<<" with : "<<endl
            <<"1. Delete First"<<endl
            <<"2. Delete Last"<<endl
            <<"3. Delete After"<<endl
            <<"0. Cancel Delete"<<endl<<endl
            <<"Choose : ";
        cin>>choose;
        cout<<endl;
        switch(choose)
        {   case '1' : delete_first_anak(adr->lanak); break;
            case '2' : delete_last_anak(adr->lanak); break;
            case '3' : delete_after_anak(adr->lanak); break;
            default  : cout<<"Delete Member Cancelled!"; break;
        }
    }
    getch();
}

void delete_first_anak(listanak &L)
{
    if(L.first != NULL)
    {
        address_anak p = L.first;
        if(p->next == NULL)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.first = p->next;
            p->next = NULL;
            L.first->prev = NULL;
        }
        cout<<"Delete Member Success!"<<endl<<endl
            <<"Member Deleted"<<endl
            <<"Member ID     : "<<info(p).id<<endl
            <<"Member Name   : "<<info(p).nama<<endl
            <<"Email         : "<<info(p).email<<endl;
        delete p;
    }
    else
    {
        cout<<"Member List is Empty, Nothing to Delete!";
    }
}

void delete_last_anak(listanak &L)
{
    address_anak Q;
    if(not list_empty_anak(L))
    {
            Q = last(L);
            if(next(first(L)) == NULL)
            {
                first(L) = NULL;
                last(L) = NULL;
            }
            else
            {
                last(L) = prev(Q);
                prev(Q) = NULL;
                next(last(L)) = NULL;
            }
            cout<<"Delete Member Success!"<<endl<<endl
                <<"Member Deleted"<<endl
                <<"Member ID     : "<<info(Q).id<<endl
                <<"Member Name   : "<<info(Q).nama<<endl
                <<"Email         : "<<info(Q).email<<endl;
            delete Q;
    }
    else
    {
        cout<<"Member List is Empty, Nothing to Delete!";
    }
}


void delete_after_anak(listanak &L)
{
    if(L.first != NULL)
    {
        infotypeanak X;
        address_anak p;
        cout<<"Delete Member After Member's ID : "; cin>>X.id;
        p = find_element_anak(L,X);
        if(p != NULL)
        {
            address_anak q = NULL;
            if(L.first->next == NULL)
            {
                q = first(L);
                first(L) = NULL;
                last(L) = NULL;
            }
            else if(p->next != NULL)
            {
                q = p->next;
                p->next = q->next;
                if(q->next != NULL)
                    q->next->prev = p;
            }
            else cout<<"Member After that ID is Empty, Delete Member Failed!"<<endl;
            if(q != NULL)
            {
                cout<<"Delete Member Success!"<<endl<<endl
                    <<"Member Deleted"<<endl
                    <<"Member ID     : "<<info(q).id<<endl
                    <<"Member Name   : "<<info(q).nama<<endl
                    <<"Email         : "<<info(q).email<<endl;
                delete q;
            }
        }
        else cout<<"ID Not Found, Delete Member Failed!"<<endl;
    }
    else cout<<"Member List is Empty, Nothing to Delete!";
}

//5. View Group
void print_info(listinduk L)
{
    cout<<"View Group"<<endl<<endl;
    if(list_empty(L))
    {
        cout<<"Group List is Empty!";
    }
    else
    {
        address p = first(L);
        while(p != Nil)
        {
            cout<<"Group ID     : "<<info(p).id<<endl
                <<"Group Name   : "<<info(p).nama<<endl
                <<"Date Created : "<<info(p).tanggal<<endl<<endl;
            p = next(p);
        }
    }
    getch();
}

//6. View Member
void print_info_anak(listinduk L)
{   //Variable
    int x = 1;
    infotypeinduk X;
    address adr;
    address_anak p;
    //Process
    cout<<"View Member"<<endl<<endl
        <<"View Member of Group (Input ID) : ";
    cin>>X.id; cout<<endl;
    adr = find_element(L,X);
    if(adr == NULL) cout<<"Group's ID not found!"<<endl;
    else
    {
        if(adr->lanak.first == NULL) cout<<"Member of Group "<<adr->info.nama<<" is Empty!"<<endl;
        else
        {   system("cls");
            cout<<"Member List of Group "<<adr->info.nama<<endl
                <<"(ID/Name/Email)"<<endl<<endl;
            p = adr->lanak.first;
            while(p != NULL)
            {   cout<<x<<". "<<p->info.id<<" / "<<p->info.nama<<" / "<<p->info.email<<endl;
                x++;
                p = p->next;
            }
        }
    }
    getch();
}

//7. Edit Group
void edit_group(listinduk &L)
{
    infotypeinduk a;
    address P;
    cout<<"Edit Group Info"<<endl<<endl
        <<"Input ID Group : ";
    cin>>a.id;
    cout<<endl;
    P=find_element(L,a);
    if(P != NULL)
    {
        cout<<"Group Name    : "<<info(P).nama<<endl
            <<"Date Created  : "<<info(P).tanggal<<endl<<endl
            <<"Change with"<<endl<<endl
            <<"Input New Info"<<endl;
        cout<<"Group Name    : "; cin>>info(P).nama;
        cout<<"Date Created  : "; cin>>info(P).tanggal;
        cout<<endl<<"Edit Group Info Success!";
    }
    else cout<<"ID Not Found, Edit Group Cancelled!";
    getch();

}
