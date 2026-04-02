//Room: /d/dali/hongsheng3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","宏聖寺塔");
	set("long",@LONG
這裏是宏聖寺塔內部，四面牆壁上都闢有佛龕，龕內置佛像。
抬頭上望，可以看到中心柱、葫蘆頂、傘蓋、相輪及蓮花座託等。
傘蓋成八角形，角上掛有風鐸。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"hongsheng2",
	    "up"     : __DIR__"hongsheng4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -55900);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	if (dir == "up" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
                if ( me->query("qi") < 20 )
                        me->unconcious();
                else
                {
                        me->add("qi", -20);
                        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<
101))
                                me->improve_skill("dodge", (int)me->query_skill("dodge",1));
                        tell_object(me,"你爬上一層樓，有些累了。\n");
                }
	}
	return 1;
}
