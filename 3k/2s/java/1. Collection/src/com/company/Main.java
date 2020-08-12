package com.company;

public class Main {

    public static void main(String[] args) throws SwapException {
        Collection collection = CollectionCreator.integer();

        System.out.println("- - Создали коллекцию");
        collection.dump();
        System.out.println();

        System.out.println("- - Количество элементов: " + collection.count());
        System.out.println("- - Максимальный элемент: " + collection.max());
        System.out.println("- - Минимальный элемент: " + collection.min());
        System.out.println("- - Сумма элементов: " + collection.sum());
        System.out.println("- - Среднее значение: " + collection.middle());
        System.out.println("- - Первое значение: " + collection.first());
        System.out.println("- - Последнее значение: " + collection.end());

        int newElement = 91;

        System.out.println("\n- - Добавим новый элемент (" + newElement + ") в коллекцию");
        collection.push(newElement);
        System.out.println("- - Количество элементов: " + collection.count());
        System.out.println("- - Последний элемент: " + collection.end());
        System.out.println();

        //

        System.out.println("- - Создадим еще одну коллекцию: ");
        Collection twoCollection = CollectionCreator.integer();

        twoCollection.dump();

        System.out.println("\n- - Объеденим: ");
        Collection mergedCollection = collection.merge(twoCollection);

        mergedCollection.dump();

        System.out.println("\n- - Количество элементов: " + mergedCollection.count());

        System.out.println("\n- - pop(): " + mergedCollection.pop());
        System.out.println("- - shift(): " + mergedCollection.shift());

        System.out.println("\n- - Количество элементов: " + mergedCollection.count());
        System.out.println("- - Отсортируем коллекцию по возрастанию");
        mergedCollection.sortByAsc().dump();

        System.out.println("\n- - Отсортируем коллекцию по убыванию");
        mergedCollection.sortByDesc().dump();

        System.out.println();

        //

        System.out.println("\n- - Найдем уникальные элементы ");
        Collection uniqueCollection = mergedCollection.unique();
        uniqueCollection.dump();

        int randomNumber = CollectionCreator.randomNumber();
        System.out.println("\n- - Выберем случайное число: " + randomNumber);
        System.out.println("- - has(" + randomNumber + "): " + uniqueCollection.has(randomNumber));
        System.out.println("- - notHas(" + randomNumber + "): " + uniqueCollection.notHas(randomNumber));
        System.out.println("- - hasValue(" + randomNumber + "): " + uniqueCollection.hasValue(randomNumber));
        System.out.println("- - notHasValue(" + randomNumber + "): " + uniqueCollection.notHasValue(randomNumber));

        //

        System.out.println("\nCollection[0] = " + uniqueCollection.get(0));
        System.out.println("Collection[1] = " + uniqueCollection.get(1));

        System.out.println("- - Поменяем местами");
        uniqueCollection.swap(0, 1);

        System.out.println("Collection[0] = " + uniqueCollection.get(0));
        System.out.println("Collection[1] = " + uniqueCollection.get(1));

        System.out.println("- - Возьмем элементы с 5 по 10");
        uniqueCollection.splice(5, 10).dump();

        System.out.println("\n- - Возьмем первые 5 элементов");
        uniqueCollection.firsts(5).dump();

        System.out.println("\n- - Возьмем последние 5 элементов");
        uniqueCollection.ends(5).dump();

        //

        System.out.println("\n- - Создадим еще одну коллекцию");

        Collection aCollection = CollectionCreator.integer();
        aCollection.dump();

        System.out.println("\n- - Перевернем ее");

        Collection bCollection = aCollection.reverse();
        bCollection.dump();

        System.out.println("\n- - Случайный элемент: " + bCollection.random());

        System.out.println("- - Перемешаем коллекцию");
        Collection cCollection = bCollection.shuffle();

        cCollection.dump();

        System.out.println("\n- - Идентичность двух последних коллекций: " + bCollection.isIdentity(cCollection));

        //

        testIntersections();
        testDeletes();
    }

    private static void testIntersections()
    {
        System.out.println("\n- - Создадим две коллекции и найдем их пересечения:");

        Collection oneCollection = CollectionCreator.integer();
        Collection twoCollection = CollectionCreator.integer();

        oneCollection.dump();
        System.out.println();
        twoCollection.dump();

        System.out.println("\n- - Пересечения");
        oneCollection.intersections(twoCollection).dump();
    }

    private static void testDeletes()
    {
        System.out.println("\n\n- - Создадим коллекцию и попробуем что-нибудь в ней удалить:");

        Collection oneCollection = CollectionCreator.integer();

        oneCollection.dump();
        System.out.println();

        int countForDelete = Helper.randomBetween(0, oneCollection.count());
        int[] valuesForDelete = new int[countForDelete];

        for (int i = 0; i < countForDelete; i++) {
            valuesForDelete[i] = oneCollection.random();
        }

        System.out.println("\n- - Выбрали значения для удаления: ");

        for (int value : valuesForDelete) {
            System.out.print(value + " ");
        }

        System.out.println("\n- - После удаления: ");

        oneCollection.deleteValues(valuesForDelete).dump();
    }
}
