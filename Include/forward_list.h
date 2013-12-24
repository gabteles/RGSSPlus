template <class T> class forward_list {
    public:
        
        struct node {
            T*    ptr;
            node* next;
        };

        forward_list(){
            this->head = NULL;
        }
		
        void push(T data){
            if (this->head == NULL){
                this->head = new node;
                this->head->ptr = &data;
            } else {
                node* point = new node;
                point->ptr  = &data;
                point->next = this->head->next;
                this->head->next  = point;
            }
        }
		
        void remove(T& data){
            if (!this->head) return;

            node* point = this->head;

            while (point->ptr == &data){
                this->head = point->next;
                delete point;

                if (!this->head) return;

                point = this->head;
            }

            if (!this->head->next) return;

            point = this->head->next;
            node* last = this->head;

            while (point->next){
                if (*point->next->ptr == data){
                        point->next = point->next->next;
                        delete point->next;
                } else {
                        last = point;
                        point = point->next;
                }
            }

            if (*point->ptr == data){
                delete point;
                last->next = NULL;
            }
        }
	
        node* head;
};