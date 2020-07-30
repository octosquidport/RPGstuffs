extends Node

onready var backColorNode = $BackColor
onready var CustomBitsClass = preload("res://Testing/simple/custombits.gdns")
var data

func _ready():
	backColorNode.rect_size = Globe.scrnDim
	
	data = CustomBitsClass.new()


func _on_Button_pressed():
	$Label.text = "Data = " + data.get_data()
	print (get_tree().get_root().size)
