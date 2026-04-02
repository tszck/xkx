// Room: /d/lingxiao/fenghuo.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","風火居");
	set("long",@LONG
這裏是雪山雙傑之一的封萬裏的房間。房間混亂不堪，到處都是刀
劍砍鑿的痕跡，好象被誰在這發泄過怒火似的。一名手持長劍，少了一
臂，而偏又面帶怒色的中年男子，站在屋中，凝望窗外，正牙關緊咬，
似有無限恨事。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/feng" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}

