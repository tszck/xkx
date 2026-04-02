//Room: hcazhengdian.c 華藏庵正殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","華藏庵正殿");
      set("long",@LONG
這裏是峨嵋山金頂華藏庵的正殿。華藏庵規模宏大，殿內青磚鋪地，中間
有普賢菩薩像，兩旁列有萬佛。正前方放一紅木供桌，陳列香燭，以供叩拜。
自此左右各有一間側殿，是接待香客的地方。南面是通往一個大廣場，只有峨
嵋弟子才能過去。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xin" : 1,
           __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"huacangan",
          "east"   : __DIR__"hcaeast", 
          "west"   : __DIR__"hcawest", 
          "south"  : __DIR__"hcaguangchang", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south" )
	{
		if(me->query("family/family_name") !="峨嵋派")
		{
				if(present("jingxin shitai", environment(me)) && living(present("jingxin shitai", environment(me))))
				{
					return notify_fail(
"靜心師太喝道：後面是本派重地，這位" + RANK_D->query_respect(me) + "請止步。\n");
				}
				else
					return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}