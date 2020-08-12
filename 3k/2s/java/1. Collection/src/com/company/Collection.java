package com.company;

import java.util.Arrays;
import java.util.stream.IntStream;

class Collection {
    private int[] items;

    public Collection(int[] items){
        this.items = items;
    }

    public int[] all()
    {
        return items;
    }

    /**
     * Получить первый элемент
     */
    public int first()
    {
        return items[0];
    }

    /**
     * Получить последний элемент
     */
    public int end()
    {
        return items[count() - 1];
    }

    /**
     * Получить последнее значение и удалить
     */
    public int pop()
    {
        int value = end();

        allocate(count() - 1);

        return value;
    }

    /**
     * Получить первое значение и удалить
     */
    public int shift()
    {
        int value = first();

        int[] newItems = new int[count() - 1];

//        for (int i = 1; i < count(); i++) {
//            newItems[i - 1] = items[i];
//        }

        if (count() - 1 >= 0) System.arraycopy(items, 1, newItems, 0, count() - 1);

        items = newItems;

        return value;
    }

    /**
     * Получить количество элементов
     */
    public int count()
    {
        return items.length;
    }

    /**
     * Существует ли элемент с индексом index
     */
    public boolean has(int index)
    {
        return index < count();
    }

    /**
     * Не существует ли элемент с индексом index
     */
    public boolean notHas(int index)
    {
        return !has(index);
    }

    /**
     * Существует ли элемент со значением value
     */
    public boolean hasValue(int value)
    {
        return searchFirstIndex(value) != -1;
    }

    /**
     * Не существует ли элемент со значением value
     */
    public boolean notHasValue(int value)
    {
        return searchFirstIndex(value) == -1;
    }

    /**
     * Найти индекс первого элемента со значением value
     */
    public int searchFirstIndex(int value)
    {
        for (int i = 0; i < count(); i++) {
            if (items[i] == value) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Получить максимальный элемент
     */
    public int max()
    {
        int max = 0;
        int elem;

        for (int i = 0; i < count(); i++) {
            elem = items[i];
            if (elem > max) {
                max = elem;
            }
        }

        return max;
    }

    /**
     * Получить минимальный элемент
     */
    public int min()
    {
        int min = 999999999;
        int elem = 0;

        for (int i = 0; i < count(); i++) {
            elem = items[i];
            if (elem < min) {
                min = elem;
            }
        }

        return min;
    }

    /**
     * Получить сумму всех элементов
     */
    public int sum()
    {
        int sum = 0;
        for (int item: items) {
            sum += item;
        }

        return sum;
    }

    /**
     * Получить среднее значение
     */
    public int middle()
    {
        return sum() / count();
    }

    /**
     * Добавить значение в коллекцию
     */
    public void push(int item)
    {
        int count = count();
        allocate(count + 1);

        items[count] = item;
    }

    /**
     * Получить уникальные элементы
     */
    public Collection unique()
    {
        int[] uniqueItems = IntStream.of(items).distinct().toArray();

        return new Collection(uniqueItems);
    }

    /**
     * Отсортировать по возрастанию
     */
    public Collection sortByAsc()
    {
        int[] newItems = items;
        Arrays.sort(newItems);

        return new Collection(newItems);
    }

    /**
     * Взять первые count элементов
     */
    public Collection firsts(int count)
    {
        return splice(0, count);
    }

    /**
     * Взять последние count элементов
     */
    public Collection ends(int count)
    {
        return splice(count() - count, count);
    }

    /**
     * Взять элементы с offset по length
     */
    public Collection splice(int offset, int length)
    {
        int endIndex = offset + length;
        if (notHas(endIndex)) {
            endIndex = count();
        }

        int[] newItems = new int[length];

        int r = 0;
        for (int i = offset; i < endIndex; i++) {
            newItems[r++] = items[i];
        }

        return new Collection(newItems);
    }

    /**
     * Отсортировать по убыванию
     */
    public Collection sortByDesc()
    {
        int[] newItems = items;
        int tmp;

        for (int i = 0; i < count(); i++) {
            for (int j = 0; j < count(); j++) {
                if (newItems[i] > newItems[j]) {
                    tmp = newItems[i];

                    newItems[i] = newItems[j];
                    newItems[j] = tmp;
                }
            }
        }

        return new Collection(newItems);
    }

    /**
     * Объединить коллекции
     */
    public Collection merge(Collection twoCollection)
    {
        int[] newItems = new int[count() + twoCollection.count()];

        for (int i = 0; i < count(); i++) {
            newItems[i] = items[i];
        }

        for (int i = 0; i < twoCollection.count(); i++) {
            newItems[count() + i] = twoCollection.get(i);
        }

        return new Collection(newItems);
    }

    /**
     * Перевернуть элементы
     */
    public Collection reverse()
    {
        int[] newItems = new int[count()];

        int index = 0;
        for (int i = count() - 1; i != - 1; i--) {
            newItems[index++] = items[i];
        }

        return new Collection(newItems);
    }

    /**
     * Получить случайный элемент коллекции
     */
    public int random()
    {
        int index = Helper.randomBetween(0, count() - 1);

        return items[index];
    }

    /**
     * Перемешать коллекцию
     */
    public Collection shuffle()
    {
        int[] newItems = new int[count()];
        boolean[] usedKeys = new boolean[count()];

        int randomIndex;

        for (int i = 0; i < count(); i++) {
            randomIndex = Helper.randomBetween(0, count());
            if (usedKeys[randomIndex]) {
                randomIndex = Helper.findFirstKey(usedKeys, false);
            }

            newItems[i] = get(randomIndex);

            usedKeys[randomIndex] = true;
        }

        return new Collection(newItems);
    }

    /**
     * Удалить значения
     */
    public Collection deleteValues(int[] values)
    {
        int[] newItems = new int[count()];

        int index = 0;
        boolean deleted = false;

        for (int i = 0; i < count() - 1; i++) {
            deleted = false;

            for (int j = 0; j < values.length - 1; j++) {
                if (get(i) == values[j]) {
                    deleted = true;
                }
            }

            if (!deleted) {
                newItems[index++] = get(i);
            }
        }

        newItems = allocate(newItems, index);

        return new Collection(newItems);
    }

    /**
     * Поиск пересечений
     */
    public Collection intersections(Collection twoCollection)
    {
        int[] newItems = new int[count() + count()];

        int index = 0;

        for (int i = 0; i < count() - 1; i++) {
            for (int j = 0; j < count() - 1; j++) {
                if (i != j && get(i) == twoCollection.get(j)) {
                    newItems[index++] = get(i);
                }
            }
        }

        newItems = allocate(newItems, index);

        return new Collection(newItems).unique();
    }

    /**
     * Являются ли коллекции идентичными: первая коллекция имеет все элементы второй коллекции (игнорируя последовательность)
     */
    public boolean isIdentity(Collection twoCollection)
    {
        int[] selfItems = sortByAsc().all();
        int[] twoItems = twoCollection.sortByAsc().all();

        if (count() != twoCollection.count()) {
            return false;
        }

        for (int i = 0; i < count(); i++) {
            if (selfItems[i] != twoItems[i]) {
                return false;
            }
        }

        return true;
    }

    /**
     * Получить index-ный элемент
     */
    public int get(int index)
    {
        return items[index];
    }

    /**
     * Поменять местами элементами
     */
    public void swap(int oneIndex, int twoIndex) throws SwapException {
        if (!has(oneIndex) || !has(twoIndex)) {
            throw new SwapException();
        }

        int tmp = items[oneIndex];
        items[oneIndex] = items[twoIndex];
        items[twoIndex] = tmp;
    }

    /**
     * Костыль для распределния памяти
     */
    private void allocate(int newCount)
    {
        this.items = allocate(items, newCount);
    }

    /**
     * Костыль для распределния памяти
     */
    private int[] allocate(int[] array, int newCount)
    {
        return Arrays.copyOf(array, newCount);
    }

    /**
     * Вывести элементы коллекции
     */
    public void dump()
    {
        for (int i = 0; i < count(); i++) {
            System.out.print(items[i] + " ");
        }
    }
}
