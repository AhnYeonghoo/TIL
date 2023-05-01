package Ch12;

import java.util.*;

public class MyVector implements List {
    Object[] data = null;
    int capacity = 0;
    int size = 0;

    public MyVector(int capacity) {
        if (capacity < 0)
            throw new IllegalArgumentException("유효하지 않은 값입니다.: " + capacity);
        this.capacity = capacity;
        data = new Object[capacity];
    }

    public MyVector() {
        this(10);
    }

    public void ensureCapacity(int minCapacity) {
        if (minCapacity - data.length > 0) {
            setCapacity(minCapacity);
        }
    }

    public boolean add(Object obj) {
        ensureCapacity(size+1);
        data[size++] = obj;
        return true;
    }

    public Object get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("범위를 벗어났습니다.");
        }

        return data[index];
    }

    @Override
    public Object set(int i, Object o) {
        return null;
    }

    @Override
    public void add(int i, Object o) {

    }

    public Object remove(int index) {
        Object oldObj = null;

        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("범위를 벗어났습니다.");

        oldObj = data[index];

        if (index != size-1) {
            System.arraycopy(data, index+1, data, index, size-index-1);
        }

        data[size-1] = null;
        size--;
        return oldObj;
    }

    @Override
    public int indexOf(Object o) {
        return 0;
    }

    @Override
    public int lastIndexOf(Object o) {
        return 0;
    }

    @Override
    public ListIterator listIterator() {
        return null;
    }

    @Override
    public ListIterator listIterator(int i) {
        return null;
    }

    @Override
    public List subList(int i, int i1) {
        return null;
    }

    public boolean remove(Object obj) {
        for (int i = 0; i < size; i++) {
            if (obj.equals(data[i])) {
                remove(i);
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean addAll(Collection collection) {
        return false;
    }

    @Override
    public boolean addAll(int i, Collection collection) {
        return false;
    }

    @Override
    public boolean retainAll(Collection collection) {
        return false;
    }

    @Override
    public boolean removeAll(Collection collection) {
        return false;
    }

    @Override
    public boolean containsAll(Collection collection) {
        return false;
    }

    public void trimToSize() {
        setCapacity(size);
    }


    public void setCapacity(int capacity) {
        if (this.capacity == capacity) return;

        Object[] temp = new Object[capacity];
        System.arraycopy(data, 0,  temp, 0, size);
        data = temp;
        this.capacity = capacity;
    }

    public void clear() {
        for (int i = 0; i < size; i++) {
            data[i] = null;
        }
        size = 0;
    }

    public Object[] toArray() {
        Object[] result = new Object[size];
        System.arraycopy(data, 0, result, 0, size);
        return result;
    }

    @Override
    public Object[] toArray(Object[] objects) {
        return new Object[0];
    }

    public boolean isEmpty() {
        return size==0;
    }

    @Override
    public boolean contains(Object o) {
        return false;
    }

    @Override
    public Iterator iterator() {
        return null;
    }

    public int getCapacity() {
        return capacity;
    }

    public int size() {
        return size;
    }


}
