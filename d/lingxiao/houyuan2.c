// Room: /d/lingxiao/houyuan2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","後園");
	set("long",@LONG 
這裏重門疊戶，是凌霄城上層人物的居所了。一般弟子要是沒什麼
事，是不能隨便進來的。旁邊幾叢綠竹，鬱鬱蔥蔥。屋柱上盡皆雕鏤着
雪花六出之形，一盆盆梅花栽種在屋廊之中。比起外面合圍粗的各色梅
樹，又是別有風情，左邊是白萬劍的家，右邊是封萬裏的住所。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"northwest" : __DIR__"zoulang3", 
		"northeast" : __DIR__"zoulang4", 
		"south"     : __DIR__"houyuan1",  
		"north"     : __DIR__"bridge", 
		"west"      : __DIR__"qihan", 
		"east"      : __DIR__"fenghuo", 
	]));
	set("objects", ([ 
	   __DIR__"obj/mei" : 2, 
	]));
	set("coor/x", -31000);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
