// Room: /d/xingxiu/job2.h
// Last Modified by winder on Apr. 25 2001

int valid_leave(object me, string dir)
{
	object ob;
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("黯然子閃身攔在你面前，喝道：臨陣想溜？給我滾回來！\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("護鏢鏢師閃身攔住你的去路，看來是想把你給廢了！\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("商隊在這裏呢，快搶(qiang)啊！\n");  
	return ::valid_leave(me, dir);
} 
