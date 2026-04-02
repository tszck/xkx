// Room: /d/nanshaolin/jieluyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <login.h>
void create()
{
	set("short", MAG"戒律院"NOR);
	set("long", @LONG
整個大殿門戶緊閉，密不透風。即便是在白晝，也猶如黑夜一般，
每隔幾步的牆上，點燃着幾枝牛油巨燭。殿上供奉着降魔韋陀下方擺着
一排排水牛皮鞭、穿孔竹板及狼牙棒等執法刑杖。四周站滿了懷抱戒刀
的執法僧兵。他們正用威嚴的眼神打量着你，令你不禁心生懼意。
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu4",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dadian" : 1,
		__DIR__"npc/zjseng" : 1,
		__DIR__"npc/slseng" : 1,
		__DIR__"npc/xiao-tong" : 1
	]));
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("coor/x", 1840);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
}

void init()
{	
	mapping fam;
	object ob;

	if( interactive(ob = this_player()) )
	{
//		if(wizardp(ob)) return;
		if( mapp(fam = ob->query("family")) &&
			fam["family_name"] == "南少林派" &&
			fam["generation"] <= 20 &&
			!ob->query("guilty") ) 
			return;
		message_vision(HIY"$N一進戒律院，...只聽幾聲大喝，如同炸雷般在大殿裏迴響。$N不禁渾身發抖，再也站立不住，腿一軟，撲通一聲跪了下來。\n\n"NOR,ob);
		ob->set("startroom", "/d/shaolin/jieluyuan");
		call_out("processing", 3, ob);
	}
}

void processing(object ob)
{
	mapping fam;

	if (!ob) return;
	write(HIW "\n你定了定神，抬頭細看，只見數十名持刀僧人將你團團圍起來，\n"
		"一片雪亮的刀光逼得你眼都睜不開。正前方的高臺上放着一把\n"
		"太師椅，居中高坐着位白鬚白眉的老僧，臉色鐵青，目射精光，\n"
		"狠狠地瞪着你。\n\n\n" NOR);
	if ( !(fam = ob->query("family")) || fam["family_name"] != "南少林派" )
	{
		message_vision(HIY "大癲一聲大喝：爾等大膽狂徒，擅闖本寺，意在不軌，該當何罪！\n堂堂南少林寺，豈能容你等宵小如此胡作非爲！執法僧兵何在！\n\n" NOR, ob);
		call_out("responsing", 3, ob, 3);
        }
	if ( (fam = ob->query("family")) && fam["family_name"] == "南少林派" ) 
	{
		if (ob->query("guilty") == 1)
			message_vision(HIY "大癲一聲大喝：$N！你離寺僅有數日，卻在外殺人越貨，胡作非爲，\n累犯大戒，敗壞本寺千載清譽！你該當何罪？！執法僧兵何在！\n\n" NOR, ob);
		if (ob->query("guilty") == 3)
			message_vision(HIY"大癲一聲大喝：$N！本寺護法松林歷代向來不許門人弟子擅入，\n你擅闖此地，意在不軌，該當何罪！執法僧兵何在！\n\n"NOR,ob);
		if (ob->query("guilty") == 2)
		{
			message_vision(HIY "大癲盯着$N看了半餉，說道：$N，你懲惡揚善，鋤暴安良，當得表彰，\n但出家人首戒殺生，你傷害人命，乃是僧家的重罪！\n你去罷，下次定不輕饒！\n\n" NOR, ob);
			ob->delete("guilty");
			ob->set("startroom", START_ROOM);
			return;
		}
		call_out("responsing1", 3, ob, 3);
	}
}

void responsing(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "僧兵大聲應道：弟子在！\n" NOR, ob);
	i--;
	j = random(3);
	if (i == 0) 
	{	
		call_out("beating", 3, ob);
		return;
	}
	call_out("responsing", j, ob, i);
}

void responsing1(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "僧兵大聲應道：弟子在！\n" NOR, ob);
	i--;
	j = random(3);
	if (i == 0) 
	{	
		call_out("beating1", 3, ob);
		return;
	}
	call_out("responsing1", j, ob, i);

}
void beating(object ob)
{

	if (!ob) return;
	message_vision(HIY "\n\n大癲喝道：杖責三百，將$N打入僧監拘押三月，非洗心悔改，\n不得釋放！意圖越獄者罪加一等！\n\n" NOR, ob);
	message_vision(HIR "僧兵們一湧而上，亂棒齊下，$N痛得昏了過去......\n" NOR, ob);
	ob->delete("guilty");
	ob->move("/d/nanshaolin/jianyu");
	ob->unconcious();
}

void beating1(object ob)
{
	int i;
	object kao;

	if (!ob) return;
	i = 20 + ob->query("combat_exp") / 100000 * 10;
	if (i > 50) i = 50;
	ob->set("carry_count", i);
	message_vision(HIY "\n\n大癲喝道：杖責三百，將$N罰去後殿挑水" + chinese_number(i) + "桶，非洗心悔改，\n不得釋放！意圖偷懶者罪加一等！\n\n" NOR, ob);
	message_vision(HIR "僧兵們一湧而上，亂棒齊下，$N痛得昏了過去......\n" NOR, ob);
	ob->delete("guilty");
	kao = new("/d/nanshaolin/obj/liao_kao");
	kao->move(ob);
        ob->unconcious();
	ob->move("/d/nanshaolin/houdian");
	ob->set("startroom", "/d/nanshaolin/houdian");
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if ( userp(me) && dir == "west" )
	{
		if( mapp(fam = me->query("family")) &&
			fam["family_name"] == "南少林派" &&
			fam["generation"] <= 20 && !me->query("guilty")) 
			return ::valid_leave(me, dir);
		else
			return notify_fail("大癲說道: 大膽，你還敢逃跑！執法僧兵何在！\n");
	}

}
