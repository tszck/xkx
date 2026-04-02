//Room: /d/dali/langan4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","杆欄中層");
	set("long",@LONG
這裏是杆欄的中層，從樓梯一上來就是祭所。南詔蠻夷大多信奉
自己部族特有的神明，家家戶戶都居中室設案供奉。中層的其餘房間
則爲寢所。此屋靠窗擺了一部紡紗機。
LONG);
	set("objects", ([
	   __DIR__"npc/fangshanu": 1,
	   __DIR__"obj/fangshaji": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"      : __DIR__"langan3",
	]));
	set("coor/x", -30950);
	set("coor/y", -70630);
	set("coor/z", 30);
	setup();
}
void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/lg4",1);
	}
}