// Room: /d/heimuya/shimen.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "石門");
	set("long", @LONG
來到一道大石門前，只見石門兩旁刻着兩行大字，右首是“文成武
德”，左首是“仁義英明”，橫額上刻着“日月光明”四個大紅字。
LONG  );
	set("outdoors", "heimuya");
	set("objects", ([
		CLASS_D("heimuya")+"/zhang2" : 1,
	]));
	set("exits", ([
	    "eastdown" : __DIR__"shijie2",
	    "westup"   : __DIR__"up1",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}