//////////////////////////////////////////////////////////////
//////////////////////  ΩÃ±€≈Ê ≈¨∑°Ω∫  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once

template <class T>

class CSingleton
{
private:
	static T* m_Single;

public:
	CSingleton()
	{

	};

	virtual ~CSingleton()
	{
		delete m_Single;
	};

	static T* GetInstance()
	{
		if (m_Single == NULL)
		{
			m_Single = new T();
		}

		return m_Single;
	};
};

template<class T>T* CSingleton<T>::m_Single = 0;