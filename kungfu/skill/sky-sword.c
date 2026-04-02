// 這是玩家自創武功程序。
// winder
// 風兒
// 桃花島第三代弟子
// 20000000
// 男性
// sword
// 天劍





inherit SKILL;

/////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
	"action" :"$N騰空躍起，一招“飛天”，手中$w衝着$n$l就是一劍",
	"damage" :50,
	"dodge" :20,
	"parry" :20,
	"damage_type": "刺傷",
	"skill_name" : "飛天"
]),
// ZHAOSHI :1

([
	"action" :"$N手腕一橫，一招“行天”，手中$w如活物掃向$n的$l",
	"damage" :80,
	"dodge" :10,
	"parry" :20,
	"damage_type": "刺傷",
	"skill_name" : "行天"
]),
// ZHAOSHI :2

([
	"action" :"$N腳尖一點，一招“沖天”，手中$w自上而下向$n的$l劈去",
	"damage" :100,
	"dodge" :10,
	"parry" :10,
	"damage_type": "刺傷",
	"skill_name" : "沖天"
]),
// ZHAOSHI :3

([
	"action" :"$N左手劍指一劃，一招“迴天”，手中$w迴轉，自下而上向$n的$l撩去",
	"damage" :130,
	"dodge" :5,
	"parry" :10,
	"damage_type": "刺傷",
	"skill_name" : "迴天"
]),
});
// ZHAOSHI :4
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的內力太弱，無法練"+"天劍"+"。\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int effective_level()
{
	return 30;
}
int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");	
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的體力不夠了，休息一下再練吧。\n");
	if( (int)me->query("neili") < 40 )
		return notify_fail("你的內力不夠了，休息一下再練吧。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
} 
string *parry_msg = ({
	"$n使出一招虛招，手中$v虛點一招，突然回招換式，護住$n的全身。\n",
});
string *unarmed_parry_msg = ({ "$n一招反攻，用手中的$v盪開了$N的招式。\n", });
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
	return -150;
}
int practice_bonus()
{
	return -150;
}
int black_white_ness()
{
	return 30;
}
string perform_action_file(string action)
{
	return CLASS_D("player") + "/"+"sword"+"/" + action;
}
