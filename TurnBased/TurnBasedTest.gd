extends Node

onready var backgroundNode : ColorRect = $BackColor

func _ready():
	var companion : int = 1; var asdf : int = 0
	
	print( companion, asdf)
	print(Globe.scrnDim)
	
	backgroundNode.rect_size = Globe.scrnDim
	
	
	
	#get_tree().quit()

