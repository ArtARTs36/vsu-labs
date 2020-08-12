/** Количество типов наследников: Формалист, Неформал, Реалист **/
#define COUNT_TYPES 3
#define COUNT_NAMES 10

#define FORMALIST_TYPE_ID 0
#define NOFORMALIST_TYPE_ID 1
#define REALIST_TYPE_ID 2

#define AGE_MIN 20
#define AGE_MAX 40

class PersonBuilder {
private:
    /**
     * Общее количество созданных людей
     *
     * Нужно для рандома, чтобы гарантированно получить 3 разных экзмемпляра
     */
    int totalCountPersons = 0;

    /**
     * Количество созданных людей в каждом типе
     */
    int *countsMakeTypes[COUNT_TYPES];

    /**
     * Количество использования каждого имени
     */
    int *countsNamesUses[COUNT_NAMES];

    resetCounts() {
        for (int i = 0; i < COUNT_TYPES; i++) {
            countsMakeTypes[i] = 0;
        }

        for (int i = 0; i < COUNT_NAMES; i++) {
            countsNamesUses[i] = 0;
        }
    }

    /**
     * Выбор имени
     */
    char *selectName() {
        char *names[] = {
                "Александр", "Андрей", "Анастасия", "Ирина", "Наталья",
                "Павел", "Роман", "Светлана", "Сергей", "Татьяна"
        };

        int id = (totalCountPersons < COUNT_NAMES) ? findExclusiveNameId() : random(0, COUNT_NAMES);

        countsNamesUses[id]++;

        return names[id];
    }

    /**
     * Ищем имя, которое еще не было использовано
     */
    int findExclusiveNameId() {
        int randId = random(0, COUNT_NAMES);

        if (countsNamesUses[randId] == 0) {
            return randId;
        }

        return findExclusiveNameId();
    }

    /**
     * Создаем человека
     */
    Person *createPerson(int typeId, char *name, int age) {
        Person *person;

        switch (typeId) {
            case FORMALIST_TYPE_ID:
                person = new Formalist(name, age);
                break;
            case NOFORMALIST_TYPE_ID:
                person = new NoFormalist(name, age);
                break;
            default:
                person = new Realist(name, age);
                break;
        }

        return person;
    }

    /**
     * Поиск ключа первого НЕиспользованного элемента в массиве
     */
    int findFirstNoUsedElem(int **counts, int max) {
        for (int i = 0; i < max; i++) {
            if (counts[i] == 0) {
                return i;
            }
        }

        return 0;
    }

    /**
     * Рандом
     * Ифы для того, чтобы не выскочить за пределы min max
     */
    int random(int min, int max) {
        int random = min + rand() % max;

        if (random > max) {
            return max;
        }

        if (min > random) {
            return min;
        }

        return random;
    }

public:

    PersonBuilder() {
        resetCounts();
    }

    /**
     * Входная точка
     */
    Person *build() {
        char *name = selectName();
        int age = random(AGE_MIN, AGE_MAX);

        int typeId = (totalCountPersons < COUNT_TYPES) ?
                     findFirstNoUsedElem(countsMakeTypes, COUNT_TYPES) : random(0, COUNT_TYPES);

        Person *person = createPerson(typeId, name, age);

        countsMakeTypes[typeId]++;
        totalCountPersons++;

        return person;
    }
};