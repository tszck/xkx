inherit ROOM;

void create()
{
        set("short", "無樂閣");
        set("long",@LONG
這是歷代大理王侯前來進香還願時休息的地方。閣內檀象寶爐，軟榻
矮几，一應俱全，清靜之中隱然透出一絲富貴之象。
LONG );
        set("exits", ([
            "north": __DIR__"xianghemen",
            "east" : __DIR__"huangtianmen",
	]));
	set("objects",([
             __DIR__"npc/xiaoshami" : 2,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37010);
	set("coor/y", -57040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}