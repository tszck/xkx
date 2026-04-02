//Room: /d/dali/yuxiashan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","玉霞山");
	set("long",@LONG
玉霞山東鎮星雲湖，山清林秀，許多遊人來此欣賞湖光山色，無
不爲之傾倒。古人有詩曰：
      玉霞悽清秋氣涼，
      星雲湖水澄明光，
      近嶼含煙凝紫翠，
      遠山峭壁摩青蒼，
      水光山色相輝映，
      萬裏無雲碧天淨。
LONG);
	set("objects", ([
	   __DIR__"npc/youke": 1,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "westdown"  : __DIR__"xingyunhu",
	]));
	set("coor/x", -30950);
	set("coor/y", -70650);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/yxs",1);
	}
}