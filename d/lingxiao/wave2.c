// Room: /d/lingxiao/wave2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰洞");
	set("long",@LONG 
這裏又是一個冰洞，但從這裏往上望，居然可以透過冰壁看到外面
的萬裏羣山。原來這外面的牆壁是懸崖上的冰層，月光射進冰洞，照得
滿洞生輝，銀光閃閃，讓人想起“冰簟銀牀夢不成，碧天如水夜雲輕”
的意境。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"enter" : __DIR__"wave", 
		"east"  : __DIR__"wave1", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31020);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

