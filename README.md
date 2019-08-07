# Морской бой на OpenGL

Описание игры..

1.Корабли покупают за золото в начале игры, без ограничения по модели и размеру.
2.есть рассы.
3.Несколько вариантов кораблей одного размера.

Способности кораблей
1.Отражать выстрел в рандомную точку чужого поля.
2.Телепортироваться после ранения.
3.Отравление - разрушает по 1 клетке за ход.
4.Несколько выстрелов.
5.Поджог територии (огонь распространяеться по соседним клеткам каждый ход).
6.Распад на осколки поражающие цель.


Функции в Qt
1.Событие клик мышки, получить координаты.
2.Вывести плоскость с изображением и определенными координатами в OpenGL
3.Таймер либо другая реализация анимации.
4.Глобальный массив , можно как член класса.
5.Айпи адрес:
получение
подключение
отправка пакетов
прием пакетов
считывание данных из пакета
подбор портов


Рандом расстановка юнитов
1.Оприделить состав моделей.
2.Начиная с больших по размеру расставлять на поле.
3.Если не помещаеться откатить обратно,поставить на другое место.
4.Если не помещаеться никак выбрать меньший корабль.

Общий алгоритм
Выбор режима игры
Выбор рассы
Закупка кораблей
Определить кто ходит
Выбор какой корабль стреляет
Выбор куда стрелять
Определить в кого попали
Отработка действий
 
