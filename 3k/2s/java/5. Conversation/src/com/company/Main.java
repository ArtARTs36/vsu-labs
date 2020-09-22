package com.company;

import java.util.Scanner;

/**
 * Диалог: Conversation
 *
 * Промоделировать разговор людей. Всего есть 5 людей. Каждый человек имеет имя (строку) и возраст (число). Установите возраст каждого человека - случайное число от 20 до 40, а имена установите случайным образом из списка «Александр», «Андрей», «Анастасия», «Ирина», «Наталья», «Павел», «Роман», «Светлана», «Сергей», «Татьяна». Любой человек способен выполнять два действия:
 *
 * здороваться с другим человеком;
 * рассказывать о себе.
 * Люди (абстрактный класс Person) делятся на 3 типа (дочерние классы):
 *
 * 1 (Формалисты) Здороваются со всеми так: «Здравствуй, <имя>», где <имя> – имя человека, с которым он здоровается.
 *
 * 2 (Неформалы) Со всеми здороваются: «Привет, <имя>!»
 *
 * 3 (Реалисты) Если возраст собеседника меньше или равен или больше не более чем на 5 лет, говорит «Привет, <имя>!», иначе «Здравствуй, <имя>».
 *
 * В программной реализации приветствие должно быть реализовано как полиморфный метод, принимающий параметр – человек и возвращающий строку. Рассказ о человеке является строкой вида «Меня зовут Вася, мой возраст 21 лет, я неформал» (вместо Вася имя человека, вместо 21 его возраст, как видите у людей с грамматикой не все в порядке и они говорят «лет» после любого числа, если хотите, можете реализовать правильную грамматику, вместо неформал может быть формалист, либо реалист). Программа должна показать информацию обо всех людях .
 *
 * Затем все люди должны поздороваться друг с другом в таком порядке: первый здоровается со вторым, потом второй с первым, потом первый с третьим, третий с первым, и так далее первый со всеми и все с первым, потом второй с третьим, третий со вторым и т.д.
 *
 * Нужно выдать в отдельных строках имя человека, который здоровается, двоеточие, приветствие
 *
 * Петя: Привет, Вася!
 *
 * Вася: Здравствуй, Петя
 *
 * Петя: Привет, Женя! ...
 */
public class Main
{
    private static final int DEFAULT_COUNT_PERSONS = 5;

    public static void main(String[] args)
    {
        int countPersons = getPersonsCount();

        Person[] persons = new Person[countPersons];
        PersonBuilder builder = new PersonBuilder();

        for (int i = 0; i < countPersons; i++) {
            persons[i] = builder.build();

            persons[i].about();
            System.out.println();
        }

        int[][] conversations = new int[countPersons][countPersons];

        for (int i = 0; i < countPersons; i++) {
            for (int j = 0; j < countPersons; j++) {
                if (i == j || conversations[i][j] > 0) {
                    continue;
                }

                System.out.println();

                persons[i].fullHello(persons[j]);

                System.out.println();

                persons[j].fullHello(persons[i]);

                conversations[i][j]++;
                conversations[j][i]++;
            }

            System.out.println();
        }
    }

    private static int getPersonsCount()
    {
        Scanner in = new Scanner(System.in);

        System.out.println("Если Вы хотите создать " + DEFAULT_COUNT_PERSONS + " персон - нажмите 0");
        System.out.println("Если хотите другое количество - введите его");

        int type = in.nextInt();

        return (type == 0) ? DEFAULT_COUNT_PERSONS : type;
    }
}