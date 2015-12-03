#include "multilist.h"

int main()
{
    //Variable Declaration
    listinduk L;
    char choose;

    create_list(L);
    while(choose != '0')
    {
        system("cls");
        cout<<"Patungan Group Main Menu"<<endl<<endl
            <<"1. Add Group"<<endl
            <<"2. Add Member"<<endl
            <<"3. Delete Group"<<endl
            <<"4. Delete Member"<<endl
            <<"5. View Group"<<endl
            <<"6. View Member"<<endl
            <<"7. Edit Group"<<endl
            <<"0. Exit"<<endl<<endl
            <<"Choose : ";
        cin>>choose;
        system("cls");

        switch(choose)
        {
            case '1' : insert_group(L); break;
            case '2' : insert_member(L); break;
            case '3' : delete_group(L); break;
            case '4' : delete_member(L); break;
            case '5' : print_info(L); break;
            case '6' : print_info_anak(L); break;
            case '7' : edit_group(L); break;
            default  : break;
        }
    }
    return 0;
}
