
	// do not modify the signature of this function
	explicit Sorter(LinkedList<T> &list, const predicate_function predicate)
	{
		// put your selection sorting code here

			LinkedList<int> temp_list;

			const int itemsSize = list.size(); 
			T* items = new T(itemsSize);
			int tmp = 0,min=0;
			for (int i = 0; !list.empty();i++) {
				items[i] = list.pop_front();
			}
		 

			for (int i = 0; i < itemsSize-1; i++) {
				min = i; 
				for (int j = i + 1; j < itemsSize; j++) {
					if (predicate(items[min], items[j])) {
						min = j;
					}
				}
				if (i != min) {
					tmp = items[i];
					items[i] = items[min];
					items[min] = tmp;
				}
			}
			for (int i = 0; i < itemsSize; i++) {
			 
				temp_list.push_back(items[i]);
			}
			list = temp_list;
	}















