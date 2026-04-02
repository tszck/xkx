//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","御街");
	set("long",@LONG
這裏就是大理的皇宮前御街，北面宮門上的匾額寫着‘聖慈宮’
三個金字。大理保定帝段正明已到天龍寺出家爲僧了，大理的軍國大
事就都在鎮南王府處置了。
LONG);
	set("outdoors", "dali");
        set("no_fight",1);
	set("objects",([
	    __DIR__"npc/weishi2": 1,
            CLASS_D("dali")+"/zhudanchen": 1, 
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"paifang",
	    "north" : __DIR__"gongmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40010);
	set("coor/y", -71000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}