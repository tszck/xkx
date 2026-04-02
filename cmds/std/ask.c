// /cmds/std/ask.c

// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Zeratul Jan 5 2001
// Modified by Constant Jan 12 2001
inherit F_CLEAN_UP;

#include <ansi.h>
object i_have(object env,string name); // env中取包含 name的物品
string filter_color(string arg);



string *msg_dunno = ({
	"$n搖搖頭，説道：沒聽説過。\n",
	"$n疑惑地看着$N，搖了搖頭。\n",
	"$n睜大眼睛望着$N，顯然不知道$P在説什麼。\n",
	"$n聳了聳肩，很抱歉地説：無可奉告。\n",
	"$n説道：嗯....這我可不清楚，你最好問問別人吧。\n",
	"$n想了一會兒，説道：對不起，你問的事我實在沒有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
//	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要問誰什麼事？\n");

//	if( !objectp(ob = present(dest, environment(me))) )
	if( !objectp(ob = i_have(environment(me),dest)) )
		return notify_fail("這裏沒有這個人。\n");

	if( !ob->is_character() ) {
		message_vision("$N對着$n自言自語....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") )
	{
		message_vision("$N向$n打聽有關『" + topic + "』的消息，但是$p顯然聽不懂人話。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打聽有關『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) || ob->query_temp("noliving") )
	{
		message_vision("但是很顯然的，$n現在的狀況沒有辦法給$N任何答覆。\n", me, ob);
		return 1;
	}
	if (topic == "本門叛徒" && ob->party_quest_betrayer(me))
		return 1;

	if (topic == "別派奸細" && ob->party_quest_thief(me))
		return 1;

	if ((topic == "quest" || topic == "江湖仇殺" ) && ob->party_quest_kill(me))
		return 1;

	if ( topic == "取消本門叛徒任務" && ob->cancle_quest_betrayer(me) )
		return 1;

	if (topic == "取消別派奸細任務" && ob->cancle_quest_thief(me))
		return 1;
		
	if (topic == "cancel" && ob->cancle_quest_kill(me))
		return 1;
		
	if (topic == "本門祕籍" && ob->party_quest_book(me))
		return 1;

	// 增加向掌門要求叛師的功能。
	// Added by Constant Jan 12 2001
	if ( (topic == "叛師" || topic == "開除") && ob->betray(me, 0))
		return 1;
		
	//增加掌門弟子向掌門要牌上俠客島
	if (topic == "俠客島" && ob->xkd(me))
		return 1;
		
		
	if (msg = ob->query("inquiry/" + topic)) {
		if (stringp(msg)) {
			message_vision( CYN "$N説道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
	{
			if (ob->accept_ask(me,topic))
			 return 1;
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
  }
	return 1;
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

    這個指令在解謎時很重要，通常必須藉由此一指令才能獲得進一步的信息。
有ｎａｍｅ、ｈｅｒｅ、ｒｕｍｏｒｓ等預設的關鍵詞。（切記：根據場景或
者金庸書中有關情節而向ＮＰＣ詢問相應的問題是破解許多ＱＵＥＳＴ的關鍵。
而對於ｎａｍｅ，ｈｅｒｅ，ｒｕｍｏｒｓ這幾個預設值，ＮＰＣ都會樂於回
答的。）

HELP
   );
   return 1;
}
