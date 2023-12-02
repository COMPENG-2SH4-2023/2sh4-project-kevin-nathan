#include "DrawnObjArray.h"

DrawnObjArray::DrawnObjArray() {
  m_nSize = 0;
  m_nCapacity = 1;
  m_ppDrawnObj = new DrawnObj*[m_nCapacity];
}

DrawnObjArray::~DrawnObjArray() {
  delete[] m_ppDrawnObj;
}

int DrawnObjArray::getSize() const {
  return m_nSize;
}

int DrawnObjArray::getCapacity() const {
  return m_nCapacity;
}

DrawnObj* DrawnObjArray::get(int nIndex) const {
  return m_ppDrawnObj[nIndex];
}

void DrawnObjArray::add(DrawnObj* pDrawnObj) {
  if (m_nSize == m_nCapacity) {
    m_nCapacity *= 2;
    DrawnObj** ppTemp = new DrawnObj*[m_nCapacity];
    for (int i = 0; i < m_nSize; i++) {
      ppTemp[i] = m_ppDrawnObj[i];
    }
    delete[] m_ppDrawnObj;
    m_ppDrawnObj = ppTemp;
  }
  m_ppDrawnObj[m_nSize] = pDrawnObj;
  m_nSize++;
}

void DrawnObjArray::remove(int nIndex) {
  for (int i = nIndex; i < m_nSize - 1; i++) {
    m_ppDrawnObj[i] = m_ppDrawnObj[i + 1];
  }
  m_nSize--;
}
