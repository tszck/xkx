// /adm/daemons/combatd.c

// Modified by Zeratul Jan 5 2001
// Modified by Constant Jan 16 2001

// #pragma optimize all
inherit F_DBASE;


#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <command.h>
#include <quest.h>



#define SETDISPLAY(x,y) (ESC+"["+x+";"+y+"f")
#define DELLINE ESC+"[K"

object *player;
int userno;

string *guard_msg = ({
	CYN "$N注視着$n的行動，企圖尋找機會出手。\n" NOR,
	CYN "$N正盯着$n的一舉一動，隨時準備發動攻勢。\n" NOR,
	CYN "$N緩緩地移動腳步，想要找出$n的破綻。\n" NOR,
	CYN "$N目不轉睛地盯着$n的動作，尋找進攻的最佳時機。\n" NOR,
	CYN "$N慢慢地移動着腳步，伺機出手。\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N和$n仇人相見分外眼紅，立刻打了起來！\n" NOR,
	HIW "$N對着$n大喝：「可惡，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二話不説就打了起來！\n" NOR,
	HIW "$N一眼瞥見$n，「哼」的一聲衝了過來！\n" NOR,
	HIW "$N一見到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我們的帳還沒算完，看招！」\n" NOR,
	HIW "$N對着$n大叫：「不知死活的東西，讓我來超渡你吧！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
	CYN "\n$N哈哈大笑，説道：承讓了！\n\n" NOR,
	CYN "\n$N雙手一拱，笑着説道：承讓！\n\n" NOR,
	CYN "\n$N勝了這招，向後躍開三尺，笑道：承讓！\n\n" NOR,
	CYN "\n$N雙手一拱，笑着説道：知道我的利害了吧！\n\n" NOR,
	CYN "\n$n向後退了幾步，説道：這場比試算我輸了，下回看我怎麼收拾你！\n\n" NOR,
	CYN "\n$n向後一縱，恨恨地説道：君子報仇，十年不晚！\n\n" NOR,
	CYN "\n$n臉色一寒，説道：算了算了，就當是我讓你吧！\n\n" NOR,
	CYN "\n$n縱聲而笑，叫道：“你運氣好！你運氣好！”一面身子向後跳開。\n\n" NOR,
	CYN "\n$n臉色微變，説道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向後退了幾步，説道：這場比試算我輸了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向後一縱，躬身做揖説道：閣下武藝不凡，果然高明！\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "戰鬥精靈");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "造成 " + damage + " 點" + type + "。\n";

	if( damage == 0 ) return "結果沒有造成任何傷害。\n";

	switch( type ) {
	case "割傷":
	case "擦傷":
	case "劈傷":
		if( damage < 10 ) return "結果只是輕輕地劃破$p的皮肉。\n";
		else if( damage < 20 ) return "結果在$p$l劃出一道細長血痕。\n";
		else if( damage < 40 ) return "結果「嗤」一聲劃出一道傷口！\n";
		else if( damage < 80 ) return "結果「嗤」地一聲劃出一道血淋淋的傷口！\n";
		else if( damage < 160 ) return "結果「嗤」地一聲劃出一道又長又深的傷口，濺得$N滿臉鮮血！\n";
		else return "結果只聽見$n一聲慘嚎，$w已在$p$l劃出一道深及見骨的可怕傷口！！\n";
		break;
	case "刺傷":
		if( damage < 10 ) return "結果只是輕輕地刺破$p的皮肉。\n";
		else if( damage < 20 ) return "結果在$p$l刺出一個創口。\n";
		else if( damage < 40 ) return "結果「噗」地一聲刺入了$n$l寸許！\n";
		else if( damage < 80 ) return "結果「噗」地一聲刺進$n的$l，使$p不由自主地退了幾步！\n";
		else if( damage < 160 ) return "結果「噗嗤」地一聲，$w已在$p$l刺出一個血肉□糊的血窟窿！\n";
		else return "結果只聽見$n一聲慘嚎，$w已在$p的$l對穿而出，鮮血濺得滿地！！\n";
		break;
	case "瘀傷":
	case "挫傷":
		if( damage < 10 ) return "結果只是輕輕地碰到，比拍蒼蠅稍微重了點。\n";
		else if( damage < 20 ) return "結果在$p的$l造成一處瘀青。\n";
		else if( damage < 40 ) return "結果一擊命中，$n的$l登時腫了一塊老高！\n";
		else if( damage < 80 ) return "結果一擊命中，$n悶哼了一聲顯然喫了不小的虧！\n";
		else if( damage < 120 ) return "結果「砰」地一聲，$n退了兩步！\n";
		else if( damage < 160 ) return "結果這一下「砰」地一聲打得$n連退了好幾步，差一點摔倒！\n";
		else if( damage < 240 ) return "結果重重地擊中，$n「哇」地一聲吐出一口鮮血！\n";
		else return "結果只聽見「砰」地一聲巨響，$n像一捆稻草般飛了出去！！\n";
		break;
	case "內傷":
		if( damage < 10 ) return "結果只是把$n打得退了半步，毫髮無損。\n";
		else if( damage < 20 ) return "結果$n痛哼一聲，在$p的$l造成一處瘀傷。\n";
		else if( damage < 40 ) return "結果一擊命中，把$n打得痛得彎下腰去！\n";
		else if( damage < 80 ) return "結果$n悶哼了一聲，臉上一陣青一陣白，顯然受了點內傷！\n";
		else if( damage < 120 ) return "結果$n臉色一下變得慘白，昏昏沉沉接連退了好幾步！\n";
		else if( damage < 160 ) return "結果重重地擊中，$n「哇」地一聲吐出一口鮮血！\n";
		else if( damage < 240 ) return "結果「轟」地一聲，$n全身氣血倒流，口中鮮血狂噴而出！\n";
		else return "結果只聽見幾聲喀喀輕響，$n一聲慘叫，像灘軟泥般塌了下去！！\n";
		break;
	case "抓傷":
		if( damage < 10 ) return "結果只是輕輕地抓破$p的皮肉。\n";
		else if( damage < 20 ) return "結果在$p$l抓出一道細長血痕。\n";
		else if( damage < 40 ) return "結果抓出一道長長的血口！\n";
		else if( damage < 80 ) return "結果抓出一道血淋淋的傷口！\n";
		else if( damage < 160 ) return "結果抓出一道又長又深的傷口，$N滿手沾滿了鮮血！\n";
		else return "結果只聽見$n一聲慘嚎，$p$l被抓出一道深及見骨的可怕傷口！！\n";
		break;
	default:
		if( !type ) type = "傷害";
		if( damage < 10 ) str = "結果只是勉強造成一處輕微";
		else if( damage < 20 ) str = "結果造成輕微的";
		else if( damage < 30 ) str = "結果造成一處";
		else if( damage < 50 ) str = "結果造成一處嚴重";
		else if( damage < 80 ) str = "結果造成頗為嚴重的";
		else if( damage < 120 ) str = "結果造成相當嚴重的";
		else if( damage < 170 ) str = "結果造成十分嚴重的";
		else if( damage < 230 ) str = "結果造成極其嚴重的";
		else str = "結果造成非常可怕的嚴重";
		return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if (ratio==100) return HIG"看起來氣血充盈，並沒有受傷。"NOR;
	if (ratio > 95) return HIG"似乎受了點輕傷，不過光從外表看不大出來。"NOR;
	if (ratio > 90) return HIY"看起來可能受了點輕傷。"NOR;
	if (ratio > 80) return HIY"受了幾處傷，不過似乎並不礙事。"NOR;
	if (ratio > 60) return HIY"受傷不輕，看起來狀況並不太好。"NOR;
	if (ratio > 40) return HIR"氣息粗重，動作開始散亂，看來所受的傷着實不輕。" NOR;
	if (ratio > 30) return HIR"已經傷痕累累，正在勉力支撐着不倒下去。"NOR;
	if (ratio > 20) return HIR"受了相當重的傷，只怕會有生命危險。"NOR;
	if (ratio > 10) return RED"傷重之下已經難以支撐，眼看就要倒在地上。"NOR;
	if (ratio > 5 ) return RED "受傷過重，已經奄奄一息，命在旦夕了。"NOR;
	return RED"受傷過重，已經有如風中殘燭，隨時都可能斷氣。"NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG"看起來充滿活力，一點也不累。"NOR;
	if( ratio > 95 ) return HIG"似乎有些疲憊，但是仍然十分有活力。"NOR;
	if( ratio > 90 ) return HIY"看起來可能有些累了。"NOR;
	if( ratio > 80 ) return HIY"動作似乎開始有點不太靈光，但是仍然有條不紊。"NOR;
	if( ratio > 60 ) return HIY"氣喘噓噓，看起來狀況並不太好。"NOR;
	if( ratio > 40 ) return HIR"似乎十分疲憊，看來需要好好休息了。"NOR;
	if( ratio > 30 ) return HIR"已經一副頭重腳輕的模樣，正在勉力支撐着不倒下去。"NOR;
	if( ratio > 20 ) return HIR"看起來已經力不從心了。"NOR;
	if( ratio > 10 ) return RED"搖頭晃腦、歪歪斜斜地站都站不穩，眼看就要倒在地上。"NOR;
	return RED"已經陷入半昏迷狀態，隨時都可能摔倒暈去。"NOR;
}

varargs void report_status(object ob, int effective)
{
// 比武現場轉播 start
	player=users();
// 比武現場轉播 end
	if( effective )
	{
		message_vision( "( $N" + eff_status_msg(
			(int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))
			+ " )\n", ob);
// 比武現場轉播 start
		if ((string)environment(ob)->query("short") == "擂臺")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
				tell_object(player[userno], "( " + ob->name() + eff_status_msg((int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))+" )\n");
// 比武現場轉播 end
	}
	else
	{
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi"))
			+ " )\n", ob);
// 比武現場轉播 start
		if ((string)environment(ob)->query("short") == "擂臺")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
				tell_object(player[userno], "( " + ob->name() + status_msg( (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n");
// 比武現場轉播 end
	}
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
 int  level, power, dex, str, exp;
	float dpower;
	string dskill;

	if( !living(ob) || ob->query_temp("noliving") ) return 0;

	level = ob->query_skill(skill);
	switch(usage)
	{
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");

/* 不同輕功有不同的威力。威力(power_point)範圍為1到1.5之間。嚴禁超標 */
			dskill = ob->query_skill_mapped("dodge");
			if( dskill )
			{
				dpower = SKILL_D(dskill)->power_point(ob);
//				if( dpower >= 1.0 && dpower <= 1.5 )
				  if( dpower < 1.0) dpower = 1.0;
			  	if (dpower > 1.5) dpower = 1.5;
					level = level * dpower;
			}
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;
/* 防止負攻防出現 */
	if (level > 800) level = 800;
	if (level < 1) level = 1;

	str = ob->query_str();
	if (str < 10 ) str = 10;
	if (str > 200 ) str = 200;
	dex = ob->query_dex();
	if (dex < 10 ) dex = 10;
	if (dex > 200 ) dex = 200;
	exp = ob->query("combat_exp");
	power = (level / 6)*level*level;

	if (usage == SKILL_USAGE_ATTACK)
		return (power+exp)/80*(str+ob->query("str"));
	else
		return (power+exp)/80*(dex+ob->query("dex"));
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type, string msg)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int wounded = 0;

	// 比武現場轉播 start
	player = users();
	// 比武現場轉播 end

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

	//
	// (0) Choose skills.
	//
	prepare = me->query_skill_prepare();
	if (!prepare)
		prepare = ([]);

	if (objectp(weapon))
		attack_skill = weapon->query("skill_type");
	else if (sizeof(prepare) == 0)
		attack_skill = "unarmed";
	else if (sizeof(prepare) == 1)
		attack_skill = (keys(prepare))[0];
	else if (sizeof(prepare) == 2)
		attack_skill = (keys(prepare))[me->query_temp("action_flag")];

	//
	// (1) Find out what action the offenser will take.
	//
	if (me->query("env/no_fight"))
		return 0;
	if (!me->query_temp("no_reset_action"))
		me->reset_action();
	else
		me->delete_temp("no_reset_action");

	action = me->query("actions");
	if (!mapp(action))
	{
		me->reset_action();
		action = me->query("action");
		if (!mapp(action))
		{
			CHANNEL_D->do_channel(this_object(), "sys", sprintf("%s(%s): bad action = %O", me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}
	result = action["action"];
	if (stringp(msg))
		result = msg;
	if (me->query_temp("action_flag") == 0)
		result = "\n" + result + "！\n";
	else
		result = "\n" + "緊跟着" + result + "！\n";

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

	// 自己先出招，對手才可能進行相應的防禦或者躲閃 //by qingyun
	result = replace_string(result, "$l", limb);
	/* 招架的兵器 體現在parry.c中 */
	if (victim->query_temp("weapon"))
		result = replace_string(result, "$W", victim->query_temp("weapon")->name());
	else
		result = replace_string(result, "$W", "拳腳");
	if (objectp(weapon))
		result = replace_string(result, "$w", weapon->name());
	else if (stringp(action["weapon"]))
		result = replace_string(result, "$w", action["weapon"]);
	else if (attack_skill == "finger")
		result = replace_string(result, "$w", "手指");
	else
		result = replace_string(result, "$w", "拳腳");

	//	message_vision(result, me, victim );
	if (!me->query("env/combatd2") &&
		(userp(me) || !victim->query("env/combatd2")))
		message_combatd(result, me, victim);
	result = "";
	// 出招結束 重設result
	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	// 限制攻防上下限, 避免負攻防
	if (ap < 1)
		ap = 1;
	if (ap > 200000000)
		ap = 200000000;

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if (action["dodge"])
	{
		if (dp > 1000000)
			dp = dp / 100 * (100 + action["dodge"]);
		else
			dp = (100 + action["dodge"]) * dp / 100;
	}
	// 限制攻防上下限, 避免負攻防
	if (dp < 1)
		dp = 1;
	if (dp > 200000000)
		dp = 200000000;
	if (victim->is_busy())
		dp /= 3;

	//
	// (3) Fight!
	//	Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//	AP and DP are greater than zero, so we always have chance to hit
	//	or be hit.
	//

	// Java 改隨機數
	//	if( random(100) > dp * 100 / (ap + dp) )
	if (random(ap + dp) < dp && !(victim->query_temp("bixie/cizu")))
	// Does the victim dodge this hit?
	// 辟邪刺足者無法躲閃
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if (!dodge_skill)
			dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if (dp < ap && (!userp(victim) || !userp(me)) && random(your["jing"] * 100 / your["max_jing"] + your["int"]) > 50)
		{
			your["combat_exp"] += 1;
			// 限制基本功夫上限
			if (victim->query_skill("dodge", 1) < 300)
				victim->improve_skill("dodge", 1);
		}

		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if ((ap < dp) && !userp(me))
		{
			if (random(my["int"]) > 15)
				my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
		}
		damage = RESULT_DODGE;
		//		if (damage<0) damage=0;
		if (wizardp(me) &&
			(string)me->query("env/combat") == "verbose")
			tell_object(me, sprintf(CYN + victim->name() + "躲避成功，躲避力：%d \n" NOR, dp));
		if (wizardp(victim) &&
			(string)victim->query("env/combat") == "verbose")
			tell_object(victim, sprintf(CYN + victim->name() + "躲避成功，躲避力：%d \n" NOR, dp));
	}
	else
	{
		//
		//	(4) Check if the victim can parry this attack.
		//

		if (victim->query_temp("weapon"))
		{
			pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
			if (!weapon)
				pp *= 2;
		}
		else
		{
			if (weapon)
				pp = 0;
			else
				pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
		}

		if (victim->is_busy())
			pp /= 3;
		if (action["parry"])
		{
			if (pp > 1000000)
				pp = pp / 100 * (100 + action["parry"]);
			else
				pp = (100 + action["parry"]) * pp / 100;
		}
		// 限制攻防上下限, 避免負攻防
		if (pp < 1)
			pp = 1;
		if (pp > 200000000)
			pp = 200000000;

		if (random(ap + pp) < pp && !(victim->query_temp("bixie/ciwan")))
		// 辟邪刺腕者無法招架
		{
			parry_skill = victim->query_skill_mapped("parry");
			if (!parry_skill ||
				!SKILL_D(parry_skill)->query_parry_msg())
				parry_skill = "parry";
			result += SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"));

			//     if (!weapon && victim->query_temp("weapon")) pp /= 2;
			//			if( pp < ap && (!userp(victim) || !userp(me))
			// 若按pp算獎勵 那麼恢復上面兩行 註釋下一行
			if (dp < ap && (!userp(victim) || !userp(me)) && random(your["jing"] * 100 / your["max_jing"] + your["int"]) > 50)
			{
				your["combat_exp"] += 1;
				// 限制基本功夫上限
				if (victim->query_skill("parry", 1) < 300)
					victim->improve_skill("parry", 1);
			}
			damage = RESULT_PARRY;
			//			if (damage<0) damage=0;
			if (wizardp(me) &&
				(string)me->query("env/combat") == "verbose")
				tell_object(me, sprintf(YEL + victim->name() + "招架成功，招架力：%d \n" NOR, pp));
			if (wizardp(victim) &&
				(string)victim->query("env/combat") == "verbose")
				tell_object(victim, sprintf(YEL + victim->name() + "招架成功，招架力：%d \n" NOR, pp));
		}
		else
		{
			//
			//	(5) We hit the victim and the victim failed to parry
			//
			if (objectp(weapon))
				damage = (int)me->query_temp("apply/damage");
			else
				damage = (int)me->query_temp("apply/unarmed_damage");
			if (damage > 300)
				damage = 300 + random(damage - 300);
			damage = (damage + random(damage)) / 2;
			if (action["damage"])
				//				damage += action["damage"] * damage / 100;
				//減弱威力
				damage += action["damage"] * damage / 200;
			// 惟有兵器有damage，拳腳命中永遠為0

			// 讓護甲可以抵消部分兵器的傷害
			// 減弱護甲作用 因damage不高 shield就顯得超強
			//			damage -= (int)victim->query_temp("apply/armor");
			defense_factor = (int)victim->query_temp("apply/armor");
			if (defense_factor > 300)
				defense_factor = 300 + random(defense_factor - 300);
			defense_factor = (defense_factor + random(defense_factor)) / 2;
			damage -= defense_factor;

			if (damage < 0)
				damage = 0;
			if (wizardp(me) &&
				(string)me->query("env/combat") == "verbose")
				tell_object(me, sprintf(GRN + "兵器傷害：%d " NOR, damage));
			if (wizardp(victim) &&
				(string)victim->query("env/combat") == "verbose")
				tell_object(victim, sprintf(GRN + "兵器傷害：%d " NOR, damage));

			damage_bonus = me->query_str();
			// Let force skill take effect.
			if (my["jiali"] && (my["neili"] > my["jiali"]))
			{
				// 內功打中的效果
				if (force_skill = me->query_skill_mapped("force"))
				{
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if (stringp(foo))
						result += foo;
					else if (intp(foo))
						damage_bonus += foo;
				}
			}
			// 被內功打中的效果 add by sega
			if (force_skill = victim->query_skill_mapped("force"))
			{
				foo = SKILL_D(force_skill)->be_hit_ob(victim, me, damage_bonus, my["jiali"]);
				if (stringp(foo))
					result += foo;
				else if (intp(foo))
					damage_bonus += foo;
			}

			if (action["force"])
				//				damage_bonus+=action["force"]*damage_bonus/100;
				// 減弱威力
				damage_bonus += action["force"] * damage_bonus / 200;
			// 打中的效果
			if (martial_skill = me->query_skill_mapped(attack_skill))
			{
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if (stringp(foo))
					result += foo;
				else if (intp(foo))
					damage_bonus += foo;
			}
			// 被打中效果 add by sega
			if (martial_skill = victim->query_skill_mapped("parry"))
			{
				foo = SKILL_D(martial_skill)->be_hit_ob(victim, me, damage_bonus);
				if (stringp(foo))
					result += foo;
				else if (intp(foo))
					damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if (weapon)
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if (stringp(foo))
					result += foo;
				else if (intp(foo))
					damage_bonus += foo;
			}
			else
			{
				foo = me->hit_ob(me, victim, damage_bonus);
				if (stringp(foo))
					result += foo;
				else if (intp(foo))
					damage_bonus += foo;
			}
			if (damage_bonus > 0)
				damage_bonus = (damage_bonus + random(damage_bonus)) / 2;
			else
				damage_bonus = 0;
			damage += damage_bonus;
			if (wizardp(me) &&
				(string)me->query("env/combat") == "verbose")
				tell_object(me, sprintf(GRN + "膂力傷害：%d " NOR, damage_bonus));
			if (wizardp(victim) &&
				(string)victim->query("env/combat") == "verbose")
				tell_object(victim, sprintf(GRN + "膂力傷害：%d " NOR, damage_bonus));
			// 無論拳腳還是兵器，膂力傷害都存在
			if (damage < 0)
				damage = 0;

			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while (random(defense_factor) > my["combat_exp"])
			{
				damage -= damage / 3;
				defense_factor /= 2;
			}

			//
			//	(6) Inflict the damage.
			//

			if (victim->query_temp("kongming"))
			// 空明拳化解傷害力
			{
				if (damage > 50)
					damage = damage / 5;
				else
					damage = 10;
			}
			if (wizardp(me) &&
				(string)me->query("env/combat") == "verbose")
				tell_object(me, sprintf(GRN + "經驗修正後傷害：%d \n" NOR, damage));
			if (wizardp(victim) &&
				(string)victim->query("env/combat") == "verbose")
				tell_object(victim, sprintf(GRN + "經驗修正後傷害：%d \n" NOR, damage));
			// 打中敵人的技能power_point的體現
			if (martial_skill = me->query_skill_mapped(attack_skill))
				if ((int)SKILL_D(martial_skill)->power_point(me) > 0)
					damage *= (int)SKILL_D(martial_skill)->power_point(me);
			//
			// 經威力系數修正後的最終傷害力
			damage = victim->receive_damage("qi", damage, me);
			if (wizardp(me) &&
				(string)me->query("env/combat") == "verbose")
				tell_object(me, sprintf(GRN + victim->name() + "所受最終傷害力：%d \n" NOR, damage));
			if (wizardp(victim) &&
				(string)victim->query("env/combat") == "verbose")
				tell_object(victim, sprintf(GRN + victim->name() + "所受最終傷害力：%d \n" NOR, damage));

			if (random(damage) > (int)victim->query_temp("apply/armor") && ((me->is_killing(victim->query("id"))) &&
																				((!weapon) && !random(4) || weapon && !random(2)) ||
																			((!weapon) && !random(7) || weapon && !random(4))))
			{
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}

			result += damage_msg(damage, action["damage_type"]);

			//
			//	(7) Give experience
			//

			if (!userp(me) || !userp(victim))
			{
				// 修改乘係數，降低增加潛能的幾率。 Modified by Constant Jan 16 2001
				if ((ap < dp) && (random(my["jing"] * 30 / my["max_jing"] + my["int"]) > 30))
				{
					my["combat_exp"] += 1;
					if (my["potential"] - my["learned_points"] < 100000)
						my["potential"] += 1;
					// 限制基本功夫上限
					if (me->query_skill(attack_skill, 1) < 300)
						me->improve_skill(attack_skill, 1);
				}
				if (random(your["max_qi"] + your["qi"]) < damage)
				{
					your["combat_exp"] += 1;
					if (your["potential"] - your["learned_points"] < 100000)
						your["potential"] += 1;
				}
			}
		}
	}

	result = replace_string(result, "$l", limb);
	/* 招架的兵器 體現在parry.c中 */
	if (victim->query_temp("weapon"))
		result = replace_string(result, "$W", victim->query_temp("weapon")->name());
	else
		result = replace_string(result, "$W", "拳腳");
	if (objectp(weapon))
		result = replace_string(result, "$w", weapon->name());
	else if (stringp(action["weapon"]))
		result = replace_string(result, "$w", action["weapon"]);
	else if (attack_skill == "finger")
		result = replace_string(result, "$w", "手指");
	else
		result = replace_string(result, "$w", "拳腳");

	if (!me->query("env/combatd2") &&
		(userp(me) || !victim->query("env/combatd2")))
		message_combatd(result, me, victim);

	// 比武現場轉播 start
	//	message_vision(result, me, victim );
	//	result = replace_string(result, "$P", me->name());
	//	result = replace_string(result, "$N", me->name());
	//	result = replace_string(result, "$n", victim->name());
	//	result = replace_string(result, "$p", victim->name());
	//	if ((string)environment(me)->query("short") == "擂臺")
	//	for (userno=0; userno<sizeof(player); userno++)
	//		if ((player[userno])->query_temp("view_leitai"))
	//			tell_object(player[userno], result);
	// 比武現場轉播 end

	if (wizardp(me) && (string)me->query("env/combat") == "verbose")
	{
		if (damage > 0)
			tell_object(me, sprintf(HIG "攻擊：%d，躲避：%d，招架：%d，傷害力：%d\n" NOR, ap / 100, dp / 100, pp / 100, damage));
		else
			tell_object(me, sprintf(HIG "攻擊：%d，躲避：%d，招架：%d\n" NOR, ap / 100, dp / 100, pp / 100));
	}
	if (wizardp(victim) && (string)victim->query("env/combat") == "verbose")
	{
		if (damage > 0)
			tell_object(victim, sprintf(HIG "攻擊：%d，躲避：%d，招架：%d，傷害力：%d\n" NOR, ap / 100, dp / 100, pp / 100, damage));
		else
			tell_object(victim, sprintf(HIG "攻擊：%d，躲避：%d，招架：%d\n" NOR, ap / 100, dp / 100, pp / 100));
	}
	// 顯示玩家精氣、氣血
	if (me->query("env/verbose"))
	{
		tell_object(me, SAVEC);
		tell_object(me, SETDISPLAY(21, 49) + DELLINE);
		tell_object(me, SETDISPLAY(22, 49) + DELLINE);
		tell_object(me, SETDISPLAY(23, 49) + DELLINE);
		tell_object(me, SETDISPLAY(21, 50) + HIY "┏--------------------------┓");
		tell_object(me, SETDISPLAY(22, 50) + HIY "┃");
		tell_object(me, SETDISPLAY(22, 52) + HIG "精：" HIR + me->query("jing") + "/" + me->query("eff_jing"));
		tell_object(me, SETDISPLAY(22, 65) + HIG "氣：" HIR + me->query("qi") + "/" + me->query("eff_qi"));
		tell_object(me, SETDISPLAY(22, 78) + HIY "┃");
		tell_object(me, SETDISPLAY(23, 50) + HIY "┗--------------------------┛" NOR);
		tell_object(me, REST);
	}
	if (damage > 0)
	{
		report_status(victim, wounded);
		if (victim->is_busy())
			victim->interrupt_me(me);
		if ((!me->is_killing(your["id"])) &&
			(!victim->is_killing(my["id"])) &&
			victim->query("qi") * 2 <= victim->query("max_qi"))
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			message_vision(winner_msg[random(sizeof(winner_msg))], me, victim);
			//			message_combatd( winner_msg[random(sizeof(winner_msg))], me, victim);
			// 比武現場轉播 start
			result = winner_msg[random(sizeof(winner_msg))];
			result = replace_string(result, "$P", me->name());
			result = replace_string(result, "$N", me->name());
			result = replace_string(result, "$n", victim->name());
			result = replace_string(result, "$p", victim->name());
			if ((string)environment(me)->query("short") == "擂臺")
				for (userno = 0; userno < sizeof(player); userno++)
					if ((player[userno])->query_temp("view_leitai") &&
						(string)environment(player[userno])->query("short") == "武道場")
						tell_object(player[userno], result);
			// 比武現場轉播 end
			return 1;
		}
	}

	if (functionp(action["post_action"]))
		evaluate(action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if (attack_type == TYPE_REGULAR && damage < 1 &&
		victim->query_temp("guarding"))
	{
		victim->set_temp("guarding", 0);
		if (random(me->query_cps()) < 5)
		{
			//			message_vision("$N一擊不中，露出了破綻！\n", me);
			message_combatd("$N一擊不中，露出了破綻！\n", me);
			// 比武現場轉播 start
			//			if ((string)environment(me)->query("short") == "擂臺")
			//			for (userno=0; userno<sizeof(player); userno++)
			//				if ((player[userno])->query_temp("view_leitai")&&
			//             (string)environment(player[userno])->query("short") == "武道場")
			//				tell_object(player[userno], me->name()+"一擊不中，露出了破綻！\n");
			// 比武現場轉播 end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		}
		else
		{
			//			message_vision("$N見$n攻擊失誤，趁機發動攻擊！\n", victim, me);
			message_combatd("$N見$n攻擊失誤，趁機發動攻擊！\n", victim, me);
			// 比武現場轉播 start
			//			if ((string)environment(me)->query("short") == "擂臺")
			//			for (userno=0; userno<sizeof(player); userno++)
			//				if ((player[userno])->query_temp("view_leitai")&&
			//             (string)environment(player[userno])->query("short") == "武道場")
			//				tell_object(player[userno], me->name()+"見"+victim->name()+"攻擊失誤，趁機發動攻擊！\n");
			// 比武現場轉播 end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
	if (martial_skill = me->query_skill_mapped(attack_skill))
		SKILL_D(martial_skill)->double_attack(me, victim);
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{

	string result;

// 比武現場轉播 start
	player=users();
// 比武現場轉播 end

	if( !living(me) || me->query_temp("noliving") ) return;

//	if( !me->visible(victim)
//	&& (random(100 + (int)me->query_skill("perception")) < 100) )
//		return;

	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() ||
		!living(victim) || victim->query_temp("noliving") )
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me))
		if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1) ||					//空手有prepare則雙擊
//			(objectp(me->query_temp("weapon")) && (me->query_temp("weapon"))->query("skill_type")=="sword" && me->query_skill("bixie-jian", 1) >= 60 && me->query_skill_mapped("sword") == "bixie-jian") || //辟邪60級以上雙擊
// 把bixie-jian雙擊做到 /kungfu/skill/bixie-jian.c 中間去
			(me->query("double_attack") && !me->query_temp("weapon")) )							//互搏空手無prepare雙擊
		{
			if (me->query("double_attack") &&
				sizeof(me->query_skill_prepare()) < 2)
				message_combatd(CYN"\n$N雙手分使，靈活異常，好象變成了兩個人似的！"NOR,me);
			me->set_temp("action_flag",1);
			do_attack(me,victim,me->query_temp("weapon"),TYPE_QUICK);
			me->set_temp("action_flag",0);
		}

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random((int)victim->query_cps()*3 ) > (int)me->query_cor())
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me))
		if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1) ||					//空手有prepare則雙擊
//			(objectp(me->query_temp("weapon")) && (me->query_temp("weapon"))->query("skill_type")=="sword" && me->query_skill("bixie-jian", 1) >= 60 && me->query_skill_mapped("sword") == "bixie-jian") || //辟邪60級以上雙擊
// bixie雙擊做到bixie-jian.c
			(me->query("double_attack") && !me->query_temp("weapon")) )							//互搏空手無prepare雙擊
		{
			if (me->query("double_attack") &&
				sizeof(me->query_skill_prepare()) < 2)
				message_combatd(CYN"\n$N雙手分使，靈活異常，好象變成了兩個人似的！"NOR,me);
			me->set_temp("action_flag",1);
			do_attack(me, victim, me->query_temp("weapon"),TYPE_REGULAR);
			me->set_temp("action_flag",0);
		}

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") )
	{
		me->set_temp("guarding", 1);
		message_vision(guard_msg[random(sizeof(guard_msg))], me,victim);
//		message_combatd(guard_msg[random(sizeof(guard_msg))], me,victim);
// 比武現場轉播 start
		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result, "$P", me->name());
		result = replace_string(result, "$N", me->name());
		result = replace_string(result, "$n", victim->name());
		result = replace_string(result, "$p", victim->name());
		if ((string)environment(me)->query("short") == "擂臺")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
				tell_object(player[userno], result);
// 比武現場轉播 end
		return;
	} else return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;
	// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight?
	|| environment(me)!=environment(obj)	// Are we still inthe same room?
	|| environment(me)->query("no_fight")	// Are we in a peace room?
	) return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N用一種異樣的眼神掃視着在場的每一個人。\n", me);

	if(random(obj->query_per()) > me->query_cps())
	{
		if(obj->query("gender")=="女性" && me->query("gender")!="女性")
		{
			message_vision("$N對着$n又多看了一眼，讚道：這麼靚麗的人兒，真不捨得下手。\n", me, obj);
			return;
		}
		if(me->query("gender")=="女性" && obj->query("gender")!="女性")
		{
			message_vision("$N對着$n又多看了一眼，讚道：這麼俊雅的可人兒，真是捨不得下手。\n", me, obj);
			return;
		}
	}
	if(!userp(me) || (int)me->query("neili")>(random(shen)+shen)/10) return;

	if( shen > (int)me->query("score") && !wizardp(obj) )
	{
		message_vision("$N對着$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你實在很不順眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else
	{
		message_vision("$N對着$n喝道：喂！" + RANK_D->query_rude(obj)
			+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩兩手吧！\n", me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist(not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight?
	|| environment(me)!=environment(obj)	// Are we still in the sameroom?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	if( me->query_temp("owner") == obj->query("id")	// be trained
	|| obj->query_temp("owner") == me->query("id") 	// be trained
	) return;

	// We found our hatred! Charge!
	message_combatd(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist( not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight?
	|| environment(me)!=environment(obj) // Are we still in the same room?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist( not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight?
	|| environment(me)!=environment(obj) // Are we still in the same room?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
// 比武現場轉播 start
	player=users();
// 比武現場轉播 end
	switch(event) {
		case "dead":
// 比武現場轉播 start
			message_vision(ob->query("dead_message"), ob);
//			message_combatd(ob->query("dead_message"), ob);
			if ((string)environment(ob)->query("short") == "擂臺")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
					tell_object(player[userno], "\n"+ob->name()+ob->query("dead_message"));
// 比武現場轉播 end
			break;
		case "unconcious":
			message_vision(ob->query("unconcious_message"), ob);
//			message_combatd(ob->query("unconcious_message"), ob);
// 比武現場轉播 start
			if ((string)environment(ob)->query("short") == "擂臺")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
//					tell_object(player[userno], "\n"+ob->name()+ob->query("unconcious_message"));
					tell_object(player[userno], "\n"+replace_string(ob->query("unconcious_message"),"$N",ob->name()));
// 比武現場轉播 end
			break;
		case "revive":
			message_vision(ob->query("revive_message"), ob);
//			message_combatd(ob->query("revive_message"), ob);
// 比武現場轉播 start
			if ((string)environment(ob)->query("short") == "擂臺")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "武道場")
//					tell_object(player[userno], "\n"+ob->name()+ob->query("revive_message"));
					tell_object(player[userno], "\n"+replace_string(ob->query("revive_message"),"$N",ob->name()));
// 比武現場轉播 end
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
 string vmark, msg="莫名其妙地死了", quest_master = "";
	mapping quest, actions;
 int bls, exp, pot, score, bonus, factor;
  object weapon,faintby;
  string msg1;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) )
	{
		killer->add("PKS", 1);
//* 對pker的限制 臨時措施 hoho
		killer->set_temp("LAST_PKER_TIME",time());

		victim->clear_condition();
// 風清揚弟子
		if (victim->query("family/master_id") == "feng qingyang")
			CHAR_D->break_relation(this_object());
			//關於風有兩個bug
			// 一個  這裏的break_relation(this_object())
			//       明顯this_object()就不對
			//另一個 char_d 中，找風清揚 用find_object load_object
			//       然後present尋找風， 但是這樣找到的feng 並沒有restore
			//       這樣的找到feng根本沒有收徒記錄
			// 因上兩個問題同時存在，所以feng弟子數不會受到影響
/* old
			victim->set("family/master_id", "yue buqun");
			victim->set("family/master_name", "嶽不羣");
			victim->set("family/generation", 14);
			victim->set("title", "華山派第十四代弟子");
			victim->set("feng_dietime",victim->query("mud_age"));
			temp = read_file("/data/FENG", 1, 1);
			student_num = atoi(temp);
			student_num--;
			if(student_num == 0) temp = "0";
			else if(student_num == 1) temp = "1";
			else if(student_num == 2) temp = "2";
			write_file("/data/FENG", temp, 1);
*/
// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
		if (victim->query("max_neili")>2)
		{
			victim->add("max_neili", -2);
		}
		victim->add("combat_exp", -(int)victim->query("combat_exp")/50);
		victim->delete("vendetta");
		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		victim->skill_death_penalty();
		if(victim->query_temp("LAST_PKER_TIME"))
			victim->delete_temp("LAST_PKER_TIME");
		victim->save();

		bls = 10;

		if(objectp(killer))
		{
			msg="被";
			 if (objectp(faintby=victim->query_temp("faint_by")) &&
      			 	faintby != killer )
			 	 msg+=sprintf("%s打暈後，被%s%s趁機",
			 	       faintby->name(1),
			 	       faintby->name(1)==killer->name(1)? "另一"+killer->query("unit"):"",
               killer->name(1));
       else
         msg+=killer->name(1);
			msg1="被";
      msg1+=killer->name(1);
			actions = killer->query("actions");
			switch(actions["damage_type"])
			{
				case "擦傷":
				case "割傷": msg+="砍死了";msg1+="砍死了"; break;
				case "刺傷": msg+="刺死了";msg1+="刺死了"; break;
				case "瘀傷": msg+="擊死了";msg1+="擊死了"; break;
				case "內傷": msg+="震死了";msg1+="震死了"; break;
				default: msg+="殺死了";msg1+="殺死了";
			}
		}
		victim->set("last_die_msg",msg);
		victim->set("last_die_by_name",killer->name());
		victim->set("last_die_by_id",killer->query("id"));
    if (victim->query("max_nuqi"))
    victim->set("nuqi",victim->query("max_nuqi"));
    victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("我看到%s"+msg1+"。真是好慘。", victim->name(1)));
		write_file("/log/static/KILLRECORD",sprintf("%s (%s) 殺死了 %s (%s) on %s\n", killer->name(1), killer->query("id"), victim->name(1), victim->query("id"), ctime(time()) ));
	}
	else
	{
		killer->add("MKS", 1);
		bls = 1;
	}
   if (victim->query("id")==killer->query("last_die_by_id"))
      {
			tell_object(killer,sprintf("你歷盡千辛萬苦，終於殺死了%s，報了血海深仇。\n", victim->name(1)));
      killer->set("nuqi",0);
      tell_object(killer,"你心中的怒氣漸漸平息了下來。\n");
      killer->delete("last_die_by_id");
      killer->delete("last_die_by_name");
      killer->delete("last_die_msg");
      victim->set("last_die_msg",sprintf("%s報仇雪恨，殺死了你",killer->name(1)));
      if (victim->query("nuqi"))
      victim->set("nuqi",victim->query("nuqi")/2);
    }
  if (objectp(weapon=killer->query_temp("weapon")) &&
  weapon->query("ownmake") && weapon->query("owner")==killer->query("id"))
   	killer->add("weapon/killed",1);
	if( (userp(killer) || killer->query("is_baby")) && killer->query("combat_exp") < victim->query("combat_exp"))
		killer->add("shen", -(int)victim->query("shen") / 10);

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

// 德望因殺人而改變 德望 -= WKS + IKS * 4 + IOKS * 8 + BKS * 2 + BOKS * 4
	if(!victim->query("family") && victim->query("race")=="人類")
	{
		killer->add("WKS", 1); // 濫殺無辜百姓哦
		if(victim->query("age") < 17 )
			killer->add("WKS1", 1); // 濫殺兒童
	}
	if(killer->query("family") &&
		killer->query("family/family_name") ==
		victim->query("family/family_name"))
	{
		killer->add("IKS", 1); // 門派內訌次數累加 internal conflict
		if(killer->query("family/generation") >
			victim->query("family/generation"))
			killer->add("IKS1", 1); // 犯上次數累加

	}
	if(killer->query("party") &&
		killer->query("party/party_name") ==
		victim->query("party/party_name"))
	{
		killer->add("BKS", 1); // 幫會內訌次數累加
		if(killer->query("party/level") <
			victim->query("party/level"))
			killer->add("BKS1", 1); // 犯上次數累加
	}
// 下面是殺人任務
	if (userp(victim) || victim->query("race")!="人類") return;
	if( interactive(killer) )
	{
		if ( ( quest = killer->query("quest/shan") ) &&
			(int)killer->query("quest/shan/time") >= time() &&
			( !killer->query("quest/shan/lock") ) &&
			( !killer->query("quest/shan/finished") ) &&
			quest["quest"]==victim->query("name"))
			quest_master = "shan";

		if ( ( quest_master == "" ) &&
			( quest = killer->query("quest/helian") ) &&
			(int)killer->query("quest/helian/time") >= time() &&
			( !killer->query("quest/helian/lock") ) &&
			( !killer->query("quest/helian/finished") ) &&
			quest["quest"]==victim->query("name"))
			quest_master = "helian";

		if ( quest_master == "" ) return;

		tell_object(killer,"恭喜你！你又完成了一項任務！\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		exp = exp * 10 / 8;
		pot = pot * 10 / 8;
		score = score * 10 / 8;
		factor=victim->query("quest/" + quest_master + "/factor");
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) killer->query("combat_exp");
		bonus += exp;
		killer->set("combat_exp", bonus);
		killer->set_temp("can_give_prize",1);
		killer->set_temp("prize_exp",exp);
		killer->set_temp("prize_pot",pot);
		killer->set_temp("prize_reason","殺人");
		bonus = (int) killer->query("potential");
		bonus = bonus - (int) killer->query("learned_points");
		bonus = bonus + pot;
//		if( bonus > 300) bonus = 300;
		bonus += (int)killer->query("learned_points");
		killer->set("potential", bonus );
		bonus = (int) killer->query("score");
		bonus += score;
		killer->set( "score", bonus );

		killer->add("shen", -(int)victim->query("shen") / 30);
/*
		bonus = (int)killer->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
		killer->set("shen", bonus);
*/
		tell_object(killer,HIW"經過你的努力拼殺，你增長了" + chinese_number(exp) + "點實戰經驗，"+ chinese_number(pot) + "點潛能和" + chinese_number(score)+"點江湖閲歷。\n" NOR);
		quest_finished( killer, quest_master );
	}
}
