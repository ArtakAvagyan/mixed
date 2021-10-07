#ifendef Vector
#define Vector

class Vector
{
	private:
	int m_capacity;
	int m_size;
	int* m_arr;
	public:
	Vector()
	{
		m_capacity = 5 ;
		m_size = 0 ;
		m_arr = new int[m_capacity];
	};
	~Vector()
	{
		delete[]m_arr;
	};
	void Vec_up()
	{
		int* tmp = new int [size*2];
	        for(int i = 0;i<m_capacity;i++){
			tmp[i]=m_arr[i]
		}
		delete[]m_arr ;
		m_arr = tmp ;
		m_capacity *= 2;
	}
	void pucsh_back(const int num)
	{
		if(m_capasity == m_size)
		{
			Vec_up();
		}
		m_arr[m_size]=num;
		++m_size;
	}
	void push_front(const int num)
	{
                if(m_capasity == m_size)
                {
                	Vec.up();
                }
		for(int i = m_size;i>=0;--i)
		{
			m_arr[i+1]=m_arr[i];
		}
 		m_arr[0]=num;
		++m_size;
	}
	int& operator[](const int num){return &m_arr[num];}
}


#endif
