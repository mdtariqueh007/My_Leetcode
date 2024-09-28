class MyCircularDeque {
    private:
    vector<int> arr;
    int front;
    int rear;
    int sz;
    int cap;
public:
    MyCircularDeque(int k) {

        arr = vector<int>(k);
        sz = 0;
        cap = k;
        front = 0;
        rear = k - 1;
        
    }
    
    bool insertFront(int value) {

        if(isFull()){
            return false;
        }

        front = (front - 1 + cap)%cap;
        arr[front] = value;
        sz++;

        return true;
        
    }
    
    bool insertLast(int value) {

        if(isFull()){
            return false;
        }

        rear = (rear + 1)%cap;
        arr[rear] = value;
        sz++;

        return true;
        
    }
    
    bool deleteFront() {

        if(isEmpty()){
            return false;
        }

        front = (front + 1)%cap;
        sz--;

        return true;
        
    }
    
    bool deleteLast() {
        
        if(isEmpty()){
            return false;
        }

        rear = (rear - 1 + cap)%cap;
        sz--;

        return true;

    }
    
    int getFront() {

        if(isEmpty()){
            return -1;
        }

        return arr[front];
        
    }
    
    int getRear() {

        if(isEmpty()){
            return -1;
        }

        return arr[rear];
        
    }
    
    bool isEmpty() {

        return sz==0;
        
    }
    
    bool isFull() {

        return sz==cap;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */