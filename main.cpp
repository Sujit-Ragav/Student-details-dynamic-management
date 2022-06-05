#include<iostream>
using namespace std;
class SNode
{
    public:
    string Name;
    int rollno;
    float cgpa;
    SNode *next;
    SNode *prev;
    SNode()
    {
        Name="";
        rollno=0;
        cgpa=0;
        next=NULL;
        prev=NULL;
    }
};
class Node
{
    public:
    string Name;
    Node *next;
    Node *prev;
    Node *down;
    SNode *student;
    Node* insertside(Node*,string);
    Node* insertdown(Node*,string,string);
    SNode* insertstudent(SNode *head,string,int,float);
    int searchdata(Node*,string);
    int studentsearch(SNode*,int);
    Node* retsearch(Node*,string);
    void display(Node*);
    void studentdisplay(SNode*);
    Node* deldept(Node*,string);
    Node* deldown(Node*,string,string);
    SNode* delstudent(SNode*,float);
    SNode* searchroll(Node*,int);
    SNode* retstudentsearch(SNode*,int);


};
SNode* Node::retstudentsearch(SNode *head,int rn)
{
    SNode *temp=head;
    if(head==NULL)
        return NULL;
    while(temp->next!=head)
        {
            if(temp->rollno==rn)
                return temp;
            else
                temp=temp->next;
        }
    if(temp->rollno==rn)
            return temp;
    return NULL;
}

SNode* Node::searchroll(Node* head,int rn)
{
    Node *temp=head;
    Node *yr=new Node();
    Node *cyr=new Node();
    Node *sec=new Node();
    Node *csec=new Node();
    SNode *stu=new SNode();
    SNode *res=NULL;

    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            yr=temp->down;
            if(yr!=NULL)
            {
                cyr=yr;
                while(yr->down!=cyr)
                {
                    sec=yr->down;
                    if(sec!=NULL)
                    {
                        csec=sec;
                        while(sec->next!=csec)
                        {stu=sec->student;
                         res=retstudentsearch(stu,rn);
                            if(res!=NULL)
                                return res;
                         sec=sec->next;
                        }
                        res=retstudentsearch(stu,rn);
                        if(res!=NULL)
                            return res;

                    }
                }
                    sec=yr->down;
                    if(sec!=NULL)
                    {
                        csec=sec;
                        while(sec->next!=csec)
                        {stu=sec->student;
                         res=retstudentsearch(stu,rn);
                            if(res!=NULL)
                                return res;
                         sec=sec->next;
                        }
                        res=retstudentsearch(stu,rn);
                        if(res!=NULL)
                            return res;

                    }
            }
        }

            yr=temp->down;
            if(yr!=NULL)
            {
                cyr=yr;
                while(yr->down!=cyr)
                {
                    sec=yr->down;
                    if(sec!=NULL)
                    {
                        csec=sec;
                        while(sec->next!=csec)
                        {stu=sec->student;
                         res=retstudentsearch(stu,rn);
                            if(res!=NULL)
                                return res;
                         sec=sec->next;
                        }
                        res=retstudentsearch(stu,rn);
                        if(res!=NULL)
                            return res;

                    }
                }
                    sec=yr->down;
                    if(sec!=NULL)
                    {
                        csec=sec;
                        while(sec->next!=csec)
                        {stu=sec->student;
                         res=retstudentsearch(stu,rn);
                            if(res!=NULL)
                                return res;
                         sec=sec->next;
                        }
                        res=retstudentsearch(stu,rn);
                        if(res!=NULL)
                            return res;

                    }
            }
            return res;
    }
    return res;
}
Node* Node::insertside(Node *head,string Name)
{
     Node *temp=new Node();
     temp->Name=Name;

    if(!searchdata(head,Name))
        cout<<"Data Present Already\n";
    else if(head==NULL)
    {

        head=temp;
        head->next=head;
        head->prev=head;

    }
    else
    {

        temp->prev=head->prev;
        temp->next=head;
        head->prev=temp;
        Node *n=head;
        while(n->next!=head)
            n=n->next;
        n->next=temp;
        head=temp;

    }
    return head;
}

Node* Node::insertdown(Node *head,string s,string p)
{
    if(!searchdata(head,s))
    {
        Node *n=head;
        while(n->Name!=s&&n->next!=head)
            n=n->next;
        n->down=insertside(n->down,p);
        return head;
    }
}

SNode* Node::insertstudent(SNode* head,string Name,int rn,float cgpa)
{
    SNode *temp=new SNode();
    temp->Name=Name;
    temp->rollno=rn;
    temp->cgpa=cgpa;

    if(!studentsearch(head,rn))
        cout<<"Student Data Present\n";
    else if(head==NULL)
    {
        head=temp;
        head->next=head;
        head->prev=head;
        return head;
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev=temp;
        SNode *n=head;
        while(n->next!=head)
            n=n->next;
        n->next=temp;
        head=temp;
        return head;
    }
}

int Node::searchdata(Node *head,string name)
{
    Node *temp=head;
    if(temp==NULL)
        return 1;
    while(temp->next!=head)
        {
            if(temp->Name==name)
                return 0;
            else
                temp=temp->next;
        }
    if(temp->Name==name)
            return 0;
    return 1;
}
int Node::studentsearch(SNode *head,int rn)
{
    SNode *temp=head;
    if(head==NULL)
        return 1;
    while(temp->next!=head)
        {
            if(temp->rollno==rn)
                return 0;
            else
                temp=temp->next;
        }
    if(temp->rollno==rn)
            return 0;
    return 1;
}

void Node::display(Node *head)
{
    if(head==NULL)
    {
        cout<<"No Data Found\n";
    }
    else
    {
        Node *temp=head;
        int i=1;
        while(temp->next!=head)
        {
            cout<<i<<"."<<temp->Name<<endl;
            i++;
            temp=temp->next;
        }
        cout<<i<<"."<<temp->Name<<endl;
    }
}
void Node::studentdisplay(SNode *head)
{
    if(head==NULL)
    {
        cout<<"No Data Found\n";
    }
    else
    {
        SNode *temp=head;
        int i=1;
        cout<<"Name\tRollno\tCGPA\n";
        while(temp->next!=head)
        {
            cout<<temp->Name<<"\t"<<temp->rollno<<"\t"<<temp->cgpa<<endl;
            i++;
            temp=temp->next;
        }
        cout<<temp->Name<<"\t"<<temp->rollno<<"\t"<<temp->cgpa<<endl;
    }
}

Node* Node::retsearch(Node *head,string name)
{
    Node *temp=head;
    if(head==NULL)
        return NULL;
    while(temp->next!=head)
        {
            if(temp->Name==name)
                return temp;
            else
                temp=temp->next;
        }
    if(temp->Name==name)
            return temp;
    return NULL;
}
Node* Node::deldept(Node* head,string name)
{
    Node* temp=head;
    if(head==NULL)
        cout<<"Empty\n";
    if(!searchdata(head,name))
    {
        if(head->next==head)
        {
            head=NULL;
            delete(temp);
        }
        else
        {
            while(temp->next->Name!=name)
                temp=temp->next;
            Node* n=temp->next;
            temp->next=n->next;
            n->next->prev=temp;
            delete(n);
        }
    }
    else
        cout<<"Data Not Found\n";
    return head;
}

Node* Node::deldown(Node* head,string name,string subname)
{
    Node *temp=retsearch(head,name);
    Node *n=temp->down;
    if(n==NULL)
        cout<<"Empty\n";
    if(!searchdata(n,subname))
    {
        if(n->next==n)
        {
            delete(n);
            temp->down=NULL;
        }
        else
        {
            while(n->next->Name!=name)
                n=n->next;
            Node* s=n->next;
            n->next=s->next;
            s->next->prev=n;
            delete(s);
        }
    }
    else
        cout<<"Data Not Found\n";
        return head;

}


SNode* Node::delstudent(SNode* head,float rn)
{
    SNode *temp=head;
    if(head==NULL)
        cout<<"Empty\n";
    if(!studentsearch(head,rn))
    {
        if(head->next==head)
        {
            head=NULL;
            delete(temp);
        }
        else
        {
            while(temp->next->rollno!=rn)
                temp=temp->next;
            SNode* n=temp->next;
            temp->next=n->next;
            n->next->prev=temp;
            delete(n);
        }
    }
    else
        cout<<"Student Not Found\n";
    return head;
}


int main()
{
    Node *head=new Node();
    head=NULL;
    int o,c,rn;
    string Name,subName;
    float cgpa;
    do
    {
        cout<<"\n\n\t\tMenu\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Update\n6.Exit\n\nEnter your choice\n";
        cin>>o;
        switch(o)
        {
        case 1:
                {
                cout<<"\n\tInsert\n1.Department\n2.Year\n3.Section\n4.Student\n\nEnter your choice:\n";
                cin>>c;
                Node *temp=new Node();
                switch(c)
                {
                case 1:
                    {
                    cout<<"Enter Dept Name\n";
                    cin>>Name;
                    head=head->insertside(head,Name);
                    break;
                    }
                case 2:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {
                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept not found\n";
                    else
                    {
                        cout<<"Enter Year to be inserted\n";
                        cin>>subName;
                        head=head->insertdown(head,Name,subName);
                    }
                    }
                    break;
                    }
                case 3:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        if(temp->down!=NULL)
                        {
                        cout<<"Enter Year to be inserted\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            cout<<"Enter Section\n";
                            cin>>subName;
                            temp=head->insertdown(temp,Name,subName);
                        }
                    }
                    }}
                    break;
                    }
                case 4:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {
                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        if(temp->down!=NULL)
                        {
                        cout<<"Enter Year to be inserted\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            head->display(temp->down);
                            cout<<"Enter Section\n";
                            cin>>Name;
                            temp=head->retsearch(temp->down,Name);
                            if(temp==NULL)
                                cout<<"Section not found\n";
                            else
                            {
                                SNode *sc=new SNode();
                                cout<<"Enter Name, rollno, cgpa\n";
                                cin>>subName>>rn>>cgpa;
                                temp->student=head->insertstudent(temp->student,subName,rn,cgpa);

                            }
                        }
                    }
                    }
                    break;
                    }
                    }
                   }
                }break;
        case 2:
            {
                cout<<"\n\tDelete\n1.Department\n2.Year\n3.Section\n4.Student\n\nEnter your choice:\n";
                cin>>c;
                Node *temp=new Node();
                switch(c)
                {
                case 1:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {
                    cout<<"Enter Dept to be deleted";
                    cin>>Name;
                    head=head->deldept(head,Name);
                    }
                    break;
                    }
                case 2:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept not found\n";
                    else
                    {
                        cout<<"Enter Year to be deleted\n";
                        cin>>subName;
                        head=head->deldown(head,Name,subName);
                    }
                    }
                    break;
                    }
                case 3:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        cout<<"Enter Year\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            cout<<"Enter Section to be deleted\n";
                            cin>>subName;
                            temp=head->deldown(temp,Name,subName);
                        }
                    }
                    }
                    break;
                    }
                case 4:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        cout<<"Enter Year\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            head->display(temp->down);
                            cout<<"Enter Section\n";
                            cin>>Name;
                            temp=head->retsearch(temp->down,Name);
                            if(temp==NULL)
                                cout<<"Section not found\n";
                            else
                            {
                                cout<<"Enter rollno\n";
                                cin>>rn;
                                temp->student=head->delstudent(temp->student,rn);
                            }
                        }
                    }
                    break;
                    }}
                    }
                    break;
            }

        case 3:
            {
                cout<<"\n\tDisplay\n1.Department\n2.Year\n3.Section\n4.Student\n\nEnter your choice:\n";
                cin>>c;
                Node *temp=new Node();
                switch(c)
                {
                case 1:
                    {
                    head->display(head);
                    break;
                    }
                case 2:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept not found\n";
                    else
                    {
                        head->display(temp->down);
                    }
                    }
                    break;
                    }
                case 3:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        cout<<"Enter Year\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            head->display(temp->down);
                        }
                    }
                    }
                    break;
                    }
                case 4:
                    {
                    head->display(head);
                    if(head!=NULL)
                    {

                    cout<<"Enter Dept\n";
                    cin>>Name;
                    temp=head->retsearch(head,Name);
                    if(temp==NULL)
                        cout<<"Dept Not Found\n";
                    else
                    {
                        head->display(temp->down);
                        cout<<"Enter Year\n";
                        cin>>Name;
                        temp=head->retsearch(temp->down,Name);
                        if(temp==NULL)
                            cout<<"Year not found\n:";
                        else
                        {
                            head->display(temp->down);
                            cout<<"Enter Section\n";
                            cin>>Name;
                            temp=head->retsearch(temp->down,Name);
                            if(temp==NULL)
                                cout<<"Section not found\n";
                            else
                            {
                                head->studentdisplay(temp->student);
                            }
                        }
                    }
                    break;
                    }}
                    }
                    break;
            }

        case 4:
            {
                SNode *temp=new SNode();
                cout<<"\nEnter roll no\n";
                cin>>rn;
                temp=head->searchroll(head,rn);
                if(temp==NULL)
                    cout<<"Student not Found\n";
                else
                    cout<<"Name:"<<temp->Name<<"\nRoll no:"<<temp->rollno<<"\nCGPA:"<<temp->cgpa<<endl;
                break;
            }
        case 5:
            {
                SNode *temp=new SNode();
                cout<<"Enter Roll no to be updated\n";
                cin>>rn;
                temp=head->searchroll(head,rn);
                if(temp==NULL)
                    cout<<"Student Not Found\n";
                else
                {
                    cout<<"1.Update Name\n2.Update cgpa\n3.No updation\n";
                    cin>>c;
                    switch(c)
                    {
                    case 1:
                        cout<<"Enter Name\n";
                        cin>>Name;
                        temp->Name=Name;
                        cout<<"Updated successfully\n";
                        break;
                    case 2:
                        cout<<"Enter rollno:\n";
                        cin>>rn;
                        temp->rollno=rn;
                        cout<<"Updated successfully\n";
                        break;
                    case 3:
                        cout<<"No updation done\n";
                        break;
                    }
                }
                break;
            }

        case 6:
            {
            cout<<"\n***Thank You***\n\n";
            break;
            }
        default:
            {
            cout<<"Enter a valid option.Try again\n";
            break;
            }
    }
    }while(o!=6);
    return 0;
}
