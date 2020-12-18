#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.3.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest732
{
	TEST_CLASS(UnitTest732)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2, colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 1, a[0][1] = 0, a[1][0] = 13, a[1][1] = -2;
			Sidlova(a, rowCount, colCount);
			Assert::AreEqual(a[0][1], 0);
			delete[] a;
		}
	};
}
