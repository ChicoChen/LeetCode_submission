class Segment{
public:
    Segment* left;    
    Segment* right;
    int start, end;
    Segment(int start, int end){
        this->start = start;
        this->end = end;
        left = NULL;
        right = NULL;
    }
};

class MyCalendar {
public:
    //learn from solution: BST
    Segment* root;
    MyCalendar() {
        root = NULL;
    }
    
    bool book(int start, int end) {
        if(!root){
            root = new Segment(start, end);
            return true;
        }

        return overlap(root, start, end);
    }

    bool overlap(Segment* node, int start, int end){

        if(start >= node->end){
            if(!node->right){
                node->right = new Segment(start, end);
                return true;
            }

            return overlap(node->right, start, end);
        }
        else if(end <= node->start){
            if(!node->left){
                node->left = new Segment(start, end);
                return true;
            }
            return overlap(node->left, start, end);
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */