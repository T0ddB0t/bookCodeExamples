class IntNode{
public:
    IntNode(){
        next = 0;
    }
    IntNode(int i, IntNode *in = 0){
        info = i; next = in;
    }
    int info;
    IntNode *next;
};

int main(){
    IntNode *p = new IntNode(10);
    p->next = new IntNode(8);
    p->next->next = new IntNode(50);
}