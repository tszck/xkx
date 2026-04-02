// Npc: /d/nanshaolin/npc/zsseng1.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
string ask_me();
string* names = ({
	"juechan shiren",
	"bichan shiren",
	"kuchan shiren",
	"kongchan shiren",
	"jichan shiren",
	"liaochan shiren",
	"mingchan shiren",
});

void create()
{
	set_name("執事僧", ({ "zhishi seng", "zhishi","seng" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "他膀大腰圓，看來長年從事體力勞動！\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", 
	([
		"心禪陣" : (: ask_me :),
		"心禪大陣" : (: ask_me :),
	]));
	create_family("南少林派", 22, "心禪堂弟子");
	setup();
}
string ask_me()
{
	mapping fam, my_fam, skl; 
	object me,fighter,room, monk;
	string *sname;
 int j;

	fighter = this_player();
	me = this_object();
	my_fam = fighter->query("family");
	skl = fighter->query_skills();
	sname = keys(skl);
	command("hmm"+fighter->query("id"));
/*
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 120) 
			return (RANK_D->query_respect(fighter) + "功力不夠，不可輕試。");
	} 
*/
	if( fighter->query("pass_xin") && !wizardp(fighter))
		return (RANK_D->query_respect(fighter) + "已是堂內高僧，可不要拿老衲開這等玩笑。");
	if( !mapp(fam = fighter->query("family")) ||
		fam["family_name"] != "南少林派")
		return (RANK_D->query_respect(fighter) + "非本派弟子，不能入堂修行。");
	if( mapp(fam = fighter->query("family")) &&
		fam["family_name"] == "南少林派" && fam["generation"] > 19 )
		return (RANK_D->query_respect(fighter) + "輩份不合，不夠資格入堂修行。");
	if ( (int)fighter->query("guilty") > 0 )
		return (RANK_D->query_respect(fighter) + "你累犯數戒，身帶重罪，還是先回去懺悔吧！\n");
	say("\n執事僧説道：好吧，我來啓動石陣機關，你決定好就化地為局(huadi)準備入陣吧。\n");
	me->set("assigned_fighter", fighter->query("id")); 		
	message_vision("\n執事僧急步離開。\n\n", fighter);
	for(j=1; j<8; j++) 
	{
		if(!( room = find_object("/d/nanshaolin/shiting" + j)) )
		room = load_object("/d/nanshaolin/shiting" + j);
		me->move(room);
		if( !objectp(monk = present(names[j-1], room) ))
		{
			me->move("/d/nanshaolin/xcping");
			message_vision("\n執事僧走了過來。\n\n", fighter);
			return "真是對不起，石亭中有石人丟竊，沒法舉行大陣了。\n"; 
		}
		message("vision", "\n執事僧走了過來，在" + monk->query("name") + "背後輕擊一掌。\n", room, monk);
		monk->move("/d/nanshaolin/xctang");
		message("vision",monk->query("name") + "隨着執事僧快步走了出去。\n", room, monk);
	}

	me->move("/d/nanshaolin/xcping");
	call_out("waiting", 1, me);
	return ("好！大家都出來了。\n");
}

void waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "執事僧説道：你比豬還慢，不等你了！\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if(!fighter->query_temp("huadi") )
	{
		if( random(10) == 0 ) 
		say("\n執事僧説道："+ RANK_D->query_respect(fighter) + "你化地為局了嗎？快點吧！\n");
		wait_time++;
		call_out("waiting", 1, me);
	}
	else call_out("preparing", 1, me, fighter);

	return;
}

int preparing(object me, object fighter)
{
 object  room;

	if(!( room = find_object("/d/nanshaolin/xcping")) )
		room = load_object("/d/nanshaolin/xcping");
//	if(!( room = find_object("/d/nanshaolin/shifang")) )
//		room = load_object("/d/nanshaolin/shifang");

	message("vision", HIY"\n執事僧大聲宣佈：心禪石人大陣啓動！\n"NOR, room);
	message("vision", "\n只聽一陣機關聲響，七個面無表情的石人堵住了通路。\n\n", room);
	room->delete("exits");
	command("chat " + fighter->query("title") + fighter->query("name") + 
	"於今日" + NATURE_D->game_time() + "挑戰心禪堂七老大陣！\n");
	fighter->delete_temp("baitie");
	fighter->delete_temp("huadi");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 8, me, fighter, 0);
	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;
	if(!( room1 = find_object("/d/nanshaolin/xcping")) )
		room1 = load_object("/d/nanshaolin/xcping");
	if(!( room2 = find_object("/d/nanshaolin/xctang")) )
		room2 = load_object("/d/nanshaolin/xctang");
	if( count < 7 )
	{
		message("vision", "\n石人各踏九宮八卦方位，緩緩而來！\n" NOR, room1);
		monk1 = present(names[count], room2);
		monk1->move(room1);
//		message_vision(HIY+monk1->query("name")+"向$N走了過來。\n"NOR, fighter);
	}
	if( count >= 1 && count <= 7 )
	{
		monk2 = present(names[count-1], room1);
		monk2->move(room2);
	}
	if (!living(fighter) || environment(fighter)!=environment(me))
	{
		if( objectp(fighter))
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);
		say("執事僧搖了搖頭，説道：我説不可輕試吧！\n\n");
		command("sigh");
		command("chat"+ "*"+ "disapp");
		call_out("do_back", 5, me );
	}
	else
	{
		if( count >= 7 )
		{
			if( (int)fighter->query_temp("beat_count") >= 7 )
				call_out("do_recruit", 5, me, fighter);
			else
				call_out("do_back", 5, me );
		}
		else
		{
			count++;
			call_out("fighting", 2, me, fighter, count);
		}
	}
	return 1;
}

int do_recruit(object me, object fighter)
{
 

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 30000);
	fighter->set("pass_xin", 1);
	say("\n執事僧説道：恭喜你闖過了心禪大陣！心禪堂又多一高僧！\n");
	command("chat 恭喜本派弟子"+fighter->query("name")+"入值心禪堂！\n");	
	call_out("do_back", 5, me );
	return 1;
}
int do_back(object me)
{
	object monk, room1, room2;
	int i;
	message("vision", "\n執事僧按動機關，石人們隨即魚貫離開。\n", environment(me) );
	
	if(!( room1 = find_object("/d/nanshaolin/xcping")) )
		room1 = load_object("/d/nanshaolin/xcping");

	for(i=1; i<8; i++) 
	{
		if(!( room2 = find_object("/d/nanshaolin/shiting" + i)) )
		room2 = load_object("/d/nanshaolin/shiting" + i);
		if( objectp( monk = present(names[i-1], room1) ));
			monk->move(room2);
	}
	me->delete("assigned_fighter");
	me->move("/d/nanshaolin/xcping");
	return 1;
} 
