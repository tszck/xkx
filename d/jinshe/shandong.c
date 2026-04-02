// shandong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
對面石壁上斜倚着一副骷髏骨，身上衣服已爛了七八成，那骷髏
骨宛然尚可見到是個人形。見石室中別無其他可怖事物。骷髏前面橫
七豎八的放着十幾把金蛇錐，石壁上有幾百幅用利器刻成的簡陋人形
(map) 。圖形盡處，石壁上出現了十六個字(word)，也是以利器所刻。
十六字之旁，有個劍柄凸出在石壁之上，似是一把劍插入了石壁，直
至劍柄。
LONG );
	set("outdoors", "jinshe");
	set("sword_count", 1);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"yongdao2",
	]));
	set("objects", ([
		__DIR__"obj/jinshe-zhui" : 1,
		__DIR__"obj/skeleton" : 1,
	]));
	set("item_desc", ([
		"劍柄" : "這是一個很奇怪的劍柄，不知道有沒有劍身。\n",
		"map"  : "石壁每個人形均不相同，舉手踢足，似在練武。\n",
		"word" : "“重寶祕術，付與有緣，入我門來，遇禍莫怨。”\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -860);
	set("coor/y", 230);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_think", "think");
	add_action("do_pull", "pull");
}
int do_pull(string arg)
{
	object ob, me= this_player();

	if (arg != "sword" && arg != "劍柄") return 0;
	if (query("sword_count") < 1)
	return notify_fail("你伸出手去拔那劍柄。不料卻撲了個空，看樣子劍已經被人取走了。\n");
	if( (int)me->query("str") < 28 )
		return notify_fail("你的臂力太小，使出喫奶的勁，劍柄依然紋絲不動。\n");
	if (this_player()->query("neili") < 2000)
	{
		message_vision(
"$N好奇心起，握住劍柄向外一拔，卻是紋絲不動，竟似鑄在石裏一般。\n", me);
		me->set("neili", 0);
		return 1;
	}
	add("sword_count", -1);
	ob = new(WEAPON_DIR"treasure/jinshe-jian");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return notify_fail("你伸出手去拔那劍柄。不料卻撲了個空，看樣子劍已經被人取走了。\n");
	}
	ob->move(me);
	message_vision(
"$N緊緊握住劍柄，潛運內力，嗤的一聲響，拔了出來，劍柄下果然連有劍身。\n", me);
	me->add("neili",-1000);
	return 1;
}
int valid_leave(object me, string dir)
{
	tell_object(this_player(),
WHT "冥冥間，虛空中有個聲音告訴你：此間有一不祥之物。 \n"+
"此物一出，人神共怖，稀世寶物，世間獨一。\n"NOR,this_player());
	return 1;
}
int do_think(string arg)
{
	object ob;
	int c_exp,c_skill;
	ob = this_player();

	if (arg != "map") return 0;
	c_skill=(int)ob->query_skill("jinshe-jian", 1);
	c_exp=ob->query("combat_exp");

	if ((c_skill*c_skill*c_skill/10)> c_exp)
	{
		message_vision("$N的實戰經驗不足，無法領悟石壁內容。\n",ob);
		return 1; 
	}
	if (ob->query("jing")<20)
	{
		message_vision("$N太累了，現在無法領悟石壁內容。\n",ob);
		return 1; 
	}
	if (c_skill> 50)
	{
		message_vision("$N覺得石壁內容太膚淺了。\n",ob);
		return 1; 
	}

	message_vision("$N面對着石壁靜思良久，對金蛇劍法似有所悟。\n",ob);
	ob->improve_skill("jinshe-jian", random(10*ob->query("int")));
	ob->receive_damage("jing", 5);
	return 1;
}
