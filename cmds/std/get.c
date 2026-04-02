// /cmds/std/get.c

// Modified by Constant Jan 6 201
inherit F_CLEAN_UP;

#include <ansi.h>


int do_get(object me, object ob);
int all;
object i_have(object env,string name); // env中取包含 name的物品
string filter_color(string arg);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount , res;
  string msg;

	all=0;
	if (!arg) return notify_fail("你要撿起什麼東西？\n");
	if (me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	if (sscanf(arg, "%s from %s", arg, from) == 2)
	{
	//	env = present(from, me);
	    env = i_have(me,from);
//		if (!env) env = present(from, environment(me));
		if (!env) env = i_have(environment(me),from);
		if (!env)
			return notify_fail("你找不到 "+from+" 這樣東西。\n");
		if ((env->query("no_get_from") ||
			living(env) && !env->query_temp("noliving/unconcious")) 
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫師等級必須比對方高，才能搜身。\n");
	} else env = environment(me);

	if (sscanf(arg, "%d %s", amount, item) == 2)
	{
	//	if (!objectp(obj = present(item, env)))
		if( !objectp(obj = i_have( env,item )) ) // env have item	
			return notify_fail("這裏沒有這樣東西。\n");
		if (!obj->query_amount())
			return notify_fail(obj->name() + "不能被分開拿走。\n");
		if (amount < 1)
			return notify_fail("東西的個數至少是一個。\n");
		if (amount > obj->query_amount())
			return notify_fail("這裏沒那麼多的"+obj->name()+"。\n");
		else
			if(amount == (int)obj->query_amount())
				return do_get(me, obj);
			else
			{
				obj2 = new(base_name(obj));
				obj2->set_amount((int)obj->query_amount()-amount);
				obj->set_amount( amount );
				res=do_get(me, obj);
				obj2->move(env);
//				if (me->is_fighting())
//					me->start_busy(3);
				return res;
			}
	}
	if (arg=="all")
	{
		if (me->is_fighting())
			return notify_fail("你還在戰鬥中！只能一次拿一樣。\n");
		if (!env->query_max_encumbrance())
			return notify_fail("那不是容器。\n");
   	if (env->is_tree())
   		return notify_fail("這是給新手活命用的，還是不要太貪心了吧n");
		inv = all_inventory(env);
		if (!sizeof(inv))
		{
   		if (env->is_tree())
         		return notify_fail("樹上什麼也沒有了。\n");
			return notify_fail("那裏面沒有任何東西。\n");
   	}        	
    if (sizeof(inv)>=20) all=1;
		for (i = 0; i < sizeof(inv); i ++)
		{
			if (inv[i]->is_character() 
			|| inv[i]->query("no_get")
			||inv[i]->query("taskobj")
			||inv[i]->query("owner"))
				continue;
			
			do_get(me, inv[i]);
		}
    if (env->is_character())
        msg = "$N從" + env->name() + "身上搜出了一堆東西。\n";
    else
     if (env == environment(me))
        msg = "$N把地上的東西都揀了起來。\n";
     else
        msg = "$N把" + env->name() + "裏面的東西都拿了出來。\n";
 
		if (all!=1)
		write("撿好了。\n");
	  else
	   message_vision(msg,me);
		return 1;
	}
//	if (!objectp(obj = present(arg, env)))
	if( !objectp(obj = i_have( env,arg )) ) // me have item	
		return notify_fail("你附近沒有這樣東西。\n");
	else
		if( userp(obj))
		{
			if(!obj->query_temp("noliving/unconcious") )
				return notify_fail("你附近沒有這樣東西。\n");
		}
		else
		{
			if(living(obj))
				return notify_fail("你附近沒有這樣東西。\n");
		}

	if (obj->query("no_get"))
	  if (stringp(obj->query("no_get")))
      return notify_fail(obj->query("no_get"));
    else
  		return notify_fail("這個東西拿不起來。\n");
	return do_get(me, obj);
}

int do_get(object me, object obj)
{
	object old_env, *guard, owner;
	int equipped;
	string msg = "";
	mapping quest;

	if (!obj) return 0;
	old_env = environment(obj);
	if (obj->query("no_get")) return 0;
	if (obj->query_temp("is_rided_by")) return 0;
        if (userp(obj) && obj->query_temp("LAST_PKER_TIME"))
                 return notify_fail("此人剛殺過人，你還是少惹為妙!\n");
        if (userp(obj) && obj->is_ghost() && !wizardp(obj))
                 return notify_fail("這東西拿不起來!\n");

        if (obj->is_character())
	{
		if (userp(obj))
		{
			if(!obj->query_temp("noliving/unconcious")) return 0;
		}
		else if (living(obj)) return 0;
	} else
		if (obj->query("no_get")) return 0;
	if (guard = obj->query_temp("guarded"))
	{
		guard = filter_array(guard, (:objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2):), me);
		if (sizeof(guard))
			return notify_fail(guard[0]->name() + "正守在" + obj->name() + "一旁，防止任何人拿走。\n");
	}
	if (obj->query("equipped")) equipped = 1;
// 限制task dummy
	if (obj->move(me))
	{
		if (me->is_fighting()) me->start_busy(1);
		if (all!=1 )
		if (obj->is_character())
			message_vision("$N將$n扶了起來背在背上。\n", me, obj);
		else
		{
			msg += "$N";
			if (old_env == environment(me))
				msg += "撿起";
			else if (old_env->is_character())
				msg += "從" + old_env->name() + "身上" + (equipped?"除下":"搜出"); 
				else if (old_env->is_tree())
					msg += "從" + old_env->name() + "摘下";
					else
					msg += "從" + old_env->name() + "拿出";
			msg += "一" + obj->query("unit");
			msg += "$n。\n";

			message_vision(msg, me, obj);
			// 原先寫法可讀性較差，改為上面的寫法。
			// Added by Constant Jan 6 2001
/*
			message_vision(sprintf("$N%s一%s$n。\n",
					old_env==environment(me)?
						"撿起"
					:(old_env->is_character()?
					  	"從" + old_env->name() + "身上" + (equipped?"除下":"搜出")
					:(old_env->is_tree()?
					  	"從" + old_env->name() + "上摘下"
					:"從" + old_env->name() + "中拿出")),
					obj->query("unit")), 
					me, obj);
*/
		}
		
		// 增加任務物品的信息顯示。
		// Added by Constant Jan 6 2001		
		if (quest = obj->query("dynamic_quest"))
		{
			if (wizardp(me) && me->query("env/no_task_msg"))
				return 1;
			if (obj->query("taskobj") && !obj->query("owner"))
			{
				obj->set("owner", me->query("id"));
				if (!objectp(owner=find_object(quest["owner_name"])))
					owner=load_object(quest["owner_name"]);
					message("channel:snow", HIY"【風聞】"HIG + me->query("name") + "找到" + owner->query("name") + HIG"的"NOR + obj->query("name") + HIG"啦！\n"NOR, users());
			}
		}
		return 1;
	}
//	else return 0;
	else return notify_fail(obj->query("name")+"對你而言太重了。\n");
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
	write(@HELP
指令格式 : get <物品名稱> [from <容器名>]
           get <物品名稱>
           get all

    這個指令可以讓你撿起地上或容器內的某樣物品。ａｌｌ參數將會把能撿
的物品全撿起來。

HELP
    );
    return 1;
}


