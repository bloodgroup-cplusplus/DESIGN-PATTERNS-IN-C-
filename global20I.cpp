#include<bits/stdc++.h>

template<typename T> class binary_indexed_tree
{
	private:
		std::vector<T> dat;
	public:
		binary_indexed_tree(){}
		explicit binary_indexed_tree(size_t N):dat(N){}
		binary_indexed_tree(size_t N, const T&t):dat(N,t){}
		size_t size() const {return dat.size();}
		const std::vector<T> & data() const {return dat;}
		std::vector<T>& data() {return dat;}

	private:
		template<typename I, typename S = I > struct iterator_range
		{
			private:
				I begin_;
				S end_;
			public:
				iterator_range() :begtin_() ,end_() {}
				iterator_range(const I&being

