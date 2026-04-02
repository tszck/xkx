//Room: sheshenya.c 捨身崖
//Date: Sep 22 1997

#include <combat.h>
#include <ansi.h>
inherit ROOM;

int fall_down(object me, string type, int stage);

string *wudang = ({
	"taiziyan",
	"guangchang",
	"zixiaogate",
	"shijie2",
	"shibapan",
	"shiliang",
	"taizipo",
	"shanlu1",
	"haohanpo",
	"wdbl",
	"yuzhengong",
	"shijie1",
	"xuanyuegate"
});

void create()
{
	set("short","捨身崖");
	set("long",@LONG
這是一處險峻的懸崖峭壁，相傳真武帝在此捨身得道。此間峯嶺奇
峭，樹木蒼翠，上接碧霄，下臨絕澗，是武當山三十六巖中最美的一處，
崖上立有鐵柵欄，防止有人自殺步真武帝的後塵。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "east"     : __DIR__"nanyanfeng",
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -940);
	set("coor/z", 110);
	setup();
}

void init()
{
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_push", "tui");
	add_action("do_push", "push");
}

int do_jump(string arg)
{
	object me = this_player();

	if( !arg || arg == "" )
		return notify_fail("什麼？\n");

	if( arg == "cliff" )
	{
		if( me->query_skill("dodge") < 150 )
			return notify_fail("那麼高的鐵柵欄，你蹦得上去麼？\n");
		message_vision("$N縱身躍過鐵柵欄，足底踏空，半個身子已在深淵之上，左足跟着跨出，全身向前急撲，往絕壁跳下！\n", me);
		me->set_temp("last_damage_from", "效仿真武跳崖飛昇了");
		fall_down(me, "char", 0);
		return 1;
	}
	return 0;
}

int do_push(string who)
{
	object me = this_player();
 object victim, weapon;
	string attack_skill, dodge_skill, parry_skill;
	int ap, dp, pp;
	mapping prepare;

	victim = present(who, environment(me));
	if( !who )return notify_fail("你想推什麼？\n");
	if( !victim ) return notify_fail("這個人不在這裏吧。\n");
	if( victim==me ) return notify_fail("指令格式：jump cliff\n");
	if( me->is_busy() )
		return notify_fail("你現在自顧都不暇，還有心思害別人？\n");
	if( !victim->is_character() || victim->query("id") == "corpse" )
		return notify_fail("要推，也只能推人下去纔有意思啊。\n");
	if( objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("拿着"+weapon->name()+"怎麼推人？\n");
	message_vision( CYN"\n$N一晃之際，已繞到$n身旁，突然勁貫雙臂，猛的將$p向峭壁推去"NOR"！\n", me, victim);
	me->start_busy(1);

	if( !living(victim) )
	{
		message_vision("$n往山谷中直栽下去。\n", me, victim);
		victim->set_temp("last_damage_from", "被"+me->name()+"推下懸崖摔死了");
		fall_down(victim, "char", 0);
		victim->revive();
		return 1;
	}

	prepare = me->query_skill_prepare();
	if( !prepare ) prepare = ([]);

	switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[random(2)]; break;
	}

	ap = COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( victim->is_busy() ) dp /= 3;

	if( random(ap + dp) < dp )
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, victim);
		if( random( ap * 2 ) < dp && !random(10) )
		{
			message_vision("$N全身力道都用在這一推之上，不料竟被$n避開，身形一晃，踏了個空，從懸崖旁摔了下去。\n", me, victim);
			me->set_temp("last_damage_from", "從百尺高空掉下，摔成一團肉泥");
			fall_down(me, "char", 0);
			return 1;
		}
		else if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
		return 1;
        }
        else
	{
		pp=COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->is_busy() ) pp /= 2;
		if( random(ap + pp) < pp )
		{
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available() ) 
				parry_skill = "parry";
			message_vision(replace_string(SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"), 
				victim), "$w", "雙手"), me, victim);
			if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
			return 1;
		}
		message_vision("$n一個沒站穩，不由自主的往山谷中掉了下去。\n", me, victim);
		victim->set_temp("last_damage_from", "被"+me->name()+"推下懸崖摔死了");
		fall_down(victim, "char", 0);
                return 1;
        }
}

int fall_down(object me, string type, int stage)
{
	object *inv; 
	int i, count;
	string dodge_skill;

	if( stage < sizeof(wudang) )
	{
		switch( random(5) )
		{
			case 1 : tell_object(me, "你只覺身子虛浮，全做不得主，只是筆直的跌落。\n");
				 break;
			case 2 : tell_object(me, "你耳旁風聲呼呼，雖是頃刻間之事，卻似無窮無盡，永遠跌個沒完。\n");
				 break;
			case 3 : tell_object(me, "你人在半空，虛虛晃晃，實是身不由己，全無半分着力處。\n");
				 break;
			case 4 : tell_object(me, "你只覺身旁風聲虎虎，身子不住的向下摔落。\n");
				 break;
			default: tell_object(me, "你但覺耳旁風聲不絕，頃刻之間，已到了");
				 break;
		}
		me->move(__DIR__+wudang[stage]);
		message("vision","你隱隱見到一人從山峯上直墮而下，一時卻看不清是誰。\n", environment(me), me);
		fall_down(me, type, ++stage);
		return 1;
	}

	inv = all_inventory(environment(me));
	for( i = 0; i < sizeof(inv); i++ ) 
		if( inv[i]->is_character() && inv[i] != me )
		{
			if( !random(25) && random(inv[i]->query_kar()) < 15 )
			{
				tell_object(inv[i],"你赫然發現那人竟是向你直衝而來！！！\n");
				tell_object(me,"你不由自主的筆直墮下，衝向一人，依稀看出是"+ inv[i]->name() +"。\n");
				if( random(inv[i]->query_skill("dodge")) > 200 )
				{
					dodge_skill = inv[i]->query_skill_mapped("dodge");
					if( !dodge_skill ) dodge_skill = "dodge";
					message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, inv[i]);
				}
				else if( !inv[i]->query_temp("weapon") &&
					random(inv[i]->query_skill("taiji-quan", 1)) > 100 &&
					inv[i]->query_skill_prepared("unarmed") == "taiji-quan" &&
					inv[i]->query_skill_mapped("parry") == "taiji-quan" )
				{
					message_vision(CYN "$N當即使出一招「攬雀尾」，右腳實，左腳虛，運起“擠”字訣，粘連粘隨，右掌已搭住$n，橫勁發出，將$p下墮之力轉直爲橫，將$n移得橫飛出去。\n"NOR, inv[i], me);
					tell_object(inv[i], HIR"你只覺霎時之間頭暈眼花，幾欲坐倒。\n"NOR);
					inv[i]->set("neili", 0);
				}
				else
				{
					count++;
					message_vision("$n直衝入$N懷中，立時撞得$P腹破腸流，死於非命。\n", inv[i], me);
					inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "被"+me->name()+"撞得腹破腸流，死於非命");
				}
			break;
			}
		}

	if( !count )
	{
		tell_object(me, "你直撞到石階上，");
		switch( random(3) )
		{
			case 0 : tell_object(me, "鮮血迸流，鼻子歪在半邊，卻便似開了個油鋪∶鹹的，酸的，辣的，一發都滾出來。\n");
				 break;
			case 1 : tell_object(me, "眼棱縫裂，烏珠迸出，也似開了個彩帛鋪的∶"HIR"紅"NOR"的，"BLU"黑"NOR"的，"MAG"紫"NOR"的，都綻將出來。\n");
				 break;
			case 2 : tell_object(me, "太陽上正着，卻似做了一全堂水陸的道場∶磐兒，鈸兒，鐃兒，一齊響。\n");
				 break;
		}
		message("vision", "只聽得「砰」的一聲巨響，" +me->name()+"撞在石階上，摔得粉身碎骨，成了一團肉漿。\n", environment(me), me);
	}

	me->receive_wound("qi", me->query("max_qi")+100, me->query_temp("last_damage_from"));

	inv = all_inventory(me);
	for( i = 0; i < sizeof(inv); i++ )
	{
		if( inv[i]->is_character() )
		inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "被"+me->name()+"連累跌得粉身碎骨了");
	}
	return 1;
}

int visit_room(string room_path, mapping info, mapping mapdb_info, mixed args)
{
	object room;

	if( strsrch(room_path, "/d/wudang/") != 0 ) return 1;
	room = find_object(room_path);
	if( !objectp(room) ) return 0;
	message("info", HIR"「啊～～～」半山突然傳來一陣極淒厲的慘叫聲。\n"NOR, room, 0);
}
