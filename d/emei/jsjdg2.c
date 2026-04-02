//Room: jsjdg2.c 九十九道拐
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","九十九道拐");
	set("long",@LONG
這是著名的「九十九道拐」，道路紆曲陡豎，千折百回。據説過去曾有個
百餘歲的瘋僧至此，見一巨蟒擋路，便唸咒驅蟒。但人們得知此處有巨蟒出沒
後，便再也無人敢碰這裏的草木，並以「龍居」名之。由此東可至千佛庵，西
達九老洞。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : __DIR__"jsjdg3",
		"eastdown"  : __DIR__"jsjdg1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6150);
	set("coor/y", -1070);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "southwest" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"你沿九十九道拐又向上爬了一陣，覺得好累。\n");
		}
	}
	return 1;
}
