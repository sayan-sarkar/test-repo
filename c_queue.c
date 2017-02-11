Multiple Circular queue in a array.
===================================


typedef struct queue_info
{
  int start_index;
  int capacity; 
  int front;
  int rear;
}queue_info;

typedef struct queue
{
  int no_q;
  queue *q;
  int *q_data;
}queue;

create_queues(int queue*, *q_capacity, q_count)
{

}

void enqueue(queue *qp, int q_index, int data)
{

}

void dequeue(queue *qp, int q_index)
{
  
}

void print_queue_by_id(int index)
{
    
}

void print_queue(int index)
{
    
}
