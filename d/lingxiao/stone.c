// Room: /d/lingxiao/stone.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "雲海石");
	set("long", @LONG
這裏放着一座碩大的石頭。是白自在從雪山絕谷中找到的奇石，上
面雲氣繚繞，佈滿了奇形怪狀的花紋。聽說在要下雨的時候，還會散發
出不同形狀的雲霧，繚繞四周，經久不散，是白自在最喜歡來賞玩的寶
物。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"meiroad2",
	]));
	set("item_desc", ([
		"stone" : "這是塊佈滿了雲氣花紋的大石，凝望着它，只見一團團雲霧似乎在不斷向前推湧，直如意欲破石飛出。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31020);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
}
void init()
{
	add_action("do_think", "think");
}

int do_think()
{
	object ob = this_player();
	int c_exp, c_skill;

	c_skill=(int)ob->query_skill("dodge", 1);
	if (c_skill <150)
	{
		message_vision("$N的基本輕功顯然太低，無法領悟雲海石內容。\n",ob);
		return 1;
	}
	c_exp=ob->query("combat_exp");
	if ((c_skill*c_skill*c_skill/10)> c_exp)
	{
		message_vision("$N的實戰經驗不足，無法領悟雲海石內容。\n",ob);
		return 1; 
	}
	if (ob->query("jing")<20)
	{
		message_vision("$N太累了，現在無法領悟雲海石內容。\n",ob);
		return 1; 
	}
	if (c_skill > 150)
	{
		message_vision("$N覺得石面內容太膚淺了。\n",ob);
		return 1; 
	}
	message_vision("$N面對着雲海石上的雲氣花紋冥思苦想，對基本輕功稍有心得。\n",ob);  
	ob->improve_skill("dodge", ((int)ob->query("int") + (int)ob->query("dex") + random(10)));
	ob->receive_damage("jing", 30);
	return 1;
}

