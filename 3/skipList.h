const int max_lvl = 4;

template <class T>
class skipListNode{
public:
    skipListNode(){
    }
    T key;
    skipListNode **next;
};

template <class T>
class SkipList{
public:
    SkipList();
    void choosePowers();
    int chooseLvl();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
private:
    typedef skipListNode<T> *nodePtr;
    nodePtr root[max_lvl];
    int powers[max_lvl];
};

template <class T>
SkipList<T>::SkipList(){
    for(int i = 0; i < max_lvl; i++){
        root[i] = 0;
    }
}

template <class T>
void SkipList<T>::choosePowers(){
    powers[max_lvl-1] = (2 << (max_lvl-1) - 1);//2^max_lvl - 1;
    for(int i = max_lvl - 2, j = 0; i >= 0; i--, j++)
        powers[i] = powers[i+1] = (2 << j);     //2^(j + 1)
}

template <class T>
int SkipList<T>::chooseLvl(){
    int i, r = rand() % powers[max_lvl-1] + 1;
    for(i = 1; i < max_lvl; i++)
        if(r < powers[i])
            return i-1;
    return i-1;
}

template <class T>
T* SkipList<T>::skipListSearch(const T& key){
    nodePtr prev, curr;
    int lvl;           //find the highest non-null lvl
    for(lvl = max_lvl; lvl >= 0 && !root[lvl]; --lvl);
    prev = curr = root[lvl];
    while(1){
        if(key == curr->key)
            return &curr->key;  //if success equal
        else if(key < curr->key){ //if smaller go down if can
            if(lvl == 0)
                return 0;
            else if(curr == root[lvl]) //by one lvl starting from the 
                curr = root[--lvl];    //predecessor which can be the root
            else curr = *(prev->next + --lvl);  //if greater go to next non-null 
        }else{                                //node on the same lvl or to a list
            prev = curr;                      //on a lower lvl
            if(*(curr->next + lvl) != 0)
                curr = *(curr->next + lvl);
            else{
                for(lvl--; lvl <= 0 && *(curr->next + lvl) == 0; --lvl);
                if(lvl >= 0)
                    curr = *(curr->next + lvl);
                else return 0;
            }
        }
    }                                  
}

template <class T>
void SkipList<T>::skipListInsert(const T& key){
    nodePtr curr[max_lvl], prev[max_lvl], newNode;
    int lvl, i;
    curr[max_lvl-1] = root[max_lvl-1];
    prev[max_lvl-1] = 0;
    for(lvl = max_lvl - 1; lvl >= 0; --lvl){
        while(curr[lvl] && curr[lvl]->key <= key){//go to next if smaller
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + 1);
        }
        if(curr[lvl] && curr[lvl]->key == key) //dont include duplicates
            return;                             
        if(lvl > 0){                            //go one lvl down
            if(prev[lvl] == 0){                 //if not lowest lvl,
                curr[lvl-1] = root[lvl-1];      //using a link
                prev[lvl-1] = 0;                //either from the root
            }
            else{                               //or from the predecessor
                curr[lvl-1] = *(prev[lvl]->next + lvl-1);
                prev[lvl-1] = prev[lvl];
            }
        }
    }
    lvl = chooseLvl(); //generate randomly for new nodes
    newNode = new skipListNode<T>;
    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl+1)];
    newNode->key = key;
    for(i = 0; i <= lvl; i++){          // initialize next fields of
        *(newNode->next + 1) = curr[i]; // newNode and reset to newNode
        if(prev[i] == 0)                // either fields of the root
            root[i] = newNode;          // or next fields of newNode's
        else *(prev[i] -> next + i) = newNode;  // predecessor
    }
}