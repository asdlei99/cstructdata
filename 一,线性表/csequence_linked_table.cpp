/***********************************************************************************************
	created: 		2019-11-04
	
	author:			chensong
					
	purpose:		线性表的课后习题
************************************************************************************************/
#ifndef _C_SEQUENCE_LINKED_TABLE_H_
#define _C_SEQUENCE_LINKED_TABLE_H_

namespace chen {
	
	static const max_size = 100;
	// 数组结构体
	struct carray
	{
		int 	m_array[max_size];
		int 	m_size; // 有数据多少个
	};
	
	
	struct carray 	g_array;
	
	//单链表
	struct clinked_list
	{
		int 				 	m_data;
		struct clinked_list * 	m_next; //下一个节点的数据
	};
	
	struct clinked_list * g_linked_list;
	
	/**
	* 数组倒序
	*/
	template <typename T>
	void array_reverse()
	{
		if (g_array.m_size <= 1)
		{
			return;
		}
		int index = 0;
		T temp = 0;
		// 这是二分查找法的思想
		while((g_array.m_size / 2) >= index)
		{
			temp = g_array.m_array[index];
			g_array.m_array[g_array.m_size - index] = temp;
			g_array.m_array[index] = temp;
			++index;
		}
		
	}
	/**
	* 删除顺序表种从start_index到end_index数据
	* @param start_index 开始位置
	* @param end_index   结束位置
	*/
	void array_delete(int start_index, int end_index)
	{
		if (g_array.m_size < end_index || g_array.m_size < start_index || start_index > end_index)
		{
			return;
		}
		// 要删除个数
		int sum = end_index - start_index + 1;
		while(sum)
		{
			g_array.m_array[start_index + sum] = g_array.m_array[end_index - sum + 1];
			--sum;
		}
		g_array.m_size -= sum;
	}
	/**
	* 插入单链表插入数据 递增 没有重复数据
	* @param data 插入的数据的值
	* {1, 1, 2, 3, 3, 3, 4, 4, 7, 7, 7, 9, 9, 9} ==> {1, 2, 3, 4, 7, 9}
	*/
	void insert_data(int data)
	{
		if (!g_linked_list)
		{
			g_linked_list = static_cast<struct clinked_list*>(::malloc(sizeof(struct clinked_list)));
			//在封装库的时候使用assert断言
			assert(g_linked_list == NULL);
			g_linked_list->m_data = 0;
			g_linked_list->m_next = NULL;
		}
		struct clinked_list * list_ptr = static_cast<struct clinked_list*>(::malloc(sizeof(struct clinked_list)));
		assert(list_ptr == NULL);
		list_ptr->m_data = data;
		list_ptr->m_next = NULL;
		//当单链表种没有数据的时候直接插入数据就可以了
		if (g_linked_list->m_data == 0)
		{
			g_linked_list->m_next = list_ptr;
			return;
		}
		struct clinked_list * next_ptr = g_linked_list->m_next;
		struct clinked_list * temp_ptr = g_linked_list->m_next; //记录上一个数据的指针
		while (next_ptr)
		{
			if (next_ptr->m_data > data)
			{
				temp_ptr->m_next = list_ptr;  //node parent -> new node
				list_ptr->m_next = next_ptr; // node new -> cur  node
				return;
			}
			else if (next_ptr->m_data < data)
			{
				temp_ptr = next_ptr;
				next_ptr = temp_ptr->m_next;
			}
			else 
			{
				return;
			}
		}
		temp_ptr->m_next = list_ptr;
	}
	/**
	* 单链表倒置
	*/
	void linked_list_reverse()
	{
		if( !g_linked_list || g_linked_list->m_data <= 1)
		{
			return;
		}
		struct clinked_list * parent_ptr = g_linked_list->m_next;
		struct clinked_list * next_ptr = parent_ptr->m_next;
		parent_ptr->m_next = NULL;
		while (next_ptr)
		{
			next_ptr->m_next = parent_ptr; //指向上一个节点
			parent_ptr = next_ptr; 
		}
		g_linked_list->m_next = parent_ptr;//指向第一个节点
	}
	
	
	
	
} // !namespace chen
#endif // !#define _C_SEQUENCE_LINKED_TABLE_H_