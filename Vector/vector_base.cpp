#include "../std_lib_facilities.h"

template<typename T, typename A>
struct vector_base {
	A alloc; 			                            	   	// allocator
	T* elem; 				                               	// start of allocation
	int sz; 				                               	// number of elements
	int space; 				                          	   	// amount of allocated space
	vector_base() :elem{ nullptr }, space{ 0 }, sz{ 0 } {};	//Default constructor for base class
	vector_base(const A& a, int n)
		: alloc{ a }, elem{ alloc.allocate(n) }, sz{ n }, space{ n }{ }

	~vector_base() { alloc.deallocate(elem, space); }
};


template<typename T, typename A = allocator<T>>
class our_vector : vector_base<T, A> {

public:

	our_vector() : vector_base<T, A>() {                                			//Default constructor
	}

	explicit our_vector(size_t s) :vector_base<T, A>(this->alloc, s) { 	            //Normal Constructor
		for (T* p = this->elem; p != this->elem + s; p++)
			this->alloc.construct(p, T());
	}

	our_vector(const our_vector<T, A>& vec);					//Copy constructor
	our_vector<T, A>& operator=(const our_vector<T, A>& vec);	//Copy Assignment
	our_vector(our_vector<T, A>&& vec);					    	//Move Constructor
	our_vector<T, A>& operator=(our_vector<T, A>&& vec);		//Move Assignment
	T& operator[](int n) { return vector_base<T, A>::elem[n]; }	//For non-const vectors
	int size() const { return this->sz; };
	void print();
	void reserve(int newalloc);
	void new_reserve(int newalloc);               				//NEW ADDED FOR TESTING
	int capacity() const { return this->space; }
	void resize(int newsize, T val = T());
	void push_back(T& val);
	T& at(int n) {
		if (n < 0 || this->sz < n)
			throw std::out_of_range("It is out of range access!");
		return this->elem[n];
	}

};

template<typename T, typename A> our_vector<T, A>::our_vector(const our_vector<T, A>& vec) :vector_base<T, A>{ vec.alloc, vec.size() } {	//Copy constructor
	copy(vec.elem, vec.elem + vec->sz, this->elem);
}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>
	::operator=(const our_vector<T, A>& vec) {                               //copy assignment
		if (this == &vec)
			return *this;
		if (vec.sz <= this->space) {								        //never decrease deallocation
			copy(vec.elem, vec.elem + vec.sz, this->elem);
			for (int i = vec.sz; i < this->sz; ++i)
				this->alloc.destroy(&this->elem[i]);
			this->sz = vec.sz;
			return *this;
		}

		T* p = this->alloc.allocate(vec.sz); 						// allocate new space
		copy(vec.elem, vec.elem + vec.sz, p); 						// copy elements
		for (int i = 0; i < this->sz; ++i) 							// deallocate old space
			this->alloc.destroy(&this->elem[i]);
		this->alloc.deallocate(this->elem, this->space);
		this->space = this->sz = vec.sz;
		this->elem = p; 									        // now we can reset elem
		return *this; 									            // return a self-reference

	}

template<typename T, typename A> our_vector<T, A>
::our_vector(our_vector<T, A>&& vec) {		                 //Move Constructore
	this->sz = vec.sz;
	this->elem = vec.elem;
	this->space = vec.space;
	vec.sz = 0;
	vec.elem = nullptr;
}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>
::operator=(our_vector<T, A>&& vec) {		           			//Move Assignment
	for (int i = 0; i < this->sz; ++i) 							// deallocate old space
		this->alloc.destroy(&this->elem[i]);
	this->alloc.deallocate(this->elem, this->space);
	this->elem = vec.elem;         		 						// copy a’s elem and sz
	this->sz = vec.sz;
	this->space = vec.space;
	vec.elem = nullptr; 		        						// make a the empty vector
	vec.sz = 0;
	return *this; 			          	 						// return a self-reference

}

template<typename T, typename A> void our_vector<T, A>::reserve(int newalloc) {		// ORIGNAL reserve
	if (newalloc <= this->space) return; 							                // never decrease allocation
	T* p = this->alloc.allocate(newalloc); 						                    // allocate new space
	for (int i = 0; i < this->sz; ++i)
		this->alloc.construct(&p[i], this->elem[i]);					            // copy old elements
	for (int i = 0; i < this->sz; ++i) 							                    // deallocate old space
		this->alloc.destroy(&this->elem[i]);
	this->alloc.deallocate(this->elem, this->space);
	this->elem = p;
	this->space = newalloc;
}

template<typename T, typename A>                                                    //NEWER RESERVE
void our_vector<T, A>::new_reserve(int newalloc) {
	if (newalloc <= this->space) return;
	vector_base<T, A> b(this->alloc, newalloc);
	uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);
	for (int i = 0; i < this->sz; ++i)
		this->alloc.destroy(&this->elem[i]);
	swap<vector_base<T, A>>(*this, b);
}

template<typename T, typename A> void our_vector<T, A>::resize(int newsize, T val) {  //Resize
	reserve(newsize);
	for (int i = this->sz; i < newsize; i++)
		this->alloc.construct(&this->elem[i], val);
	for (int i = newsize; i < this->sz; i++)
		this->alloc.destroy(&this->elem[i]);
	this->sz = newsize;
}

template<typename T, typename A> void our_vector<T, A>::push_back(T& val) {  		//increase vector size by one; initialize the new element with d
	if (this->space == 0)
		reserve(8); 								                                // start with space for 8 elements
	else if (this->sz == this->space)
		reserve(2 * this->space); 							                        // get more space
	this->alloc.construct(&this->elem[this->sz], val);
	++this->sz; 										                            // increase the size (sz is the number of elements)
}

template<typename T, typename A> void our_vector<T, A>::print() {
	for (int i = 0; i < this->sz; i++) {
		cout << this->elem[i] << " ";
	}
	cout << endl;
}



int main() {
	cout << "\n\n-----Test code!-------\n\n\n";

	our_vector<double>* n_p = new our_vector<double>();
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	n_p->resize(10);
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	double x = 2;
	n_p->push_back(x);

	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;
	n_p->print();

	//Copy check
	our_vector<double>* copy_p(n_p);
	cout << copy_p->size() << endl;
	cout << copy_p->capacity() << endl;
	copy_p->print();

	our_vector<double>* copy_assign = copy_p;
	cout << copy_assign->size() << endl;
	cout << copy_assign->capacity() << endl;
	copy_assign->print();

	our_vector<string> w(2);
	w[0] = "first";
	w[1] = "second";
	w.print();

	try {
		our_vector<string> p(2);
		p[0] = "first";
		p[1] = "second";                  
		cout << p.at(3)<< endl;
	}
	catch(out_of_range e){
		cerr << e.what() << endl;
	}
	
	return 0;
}