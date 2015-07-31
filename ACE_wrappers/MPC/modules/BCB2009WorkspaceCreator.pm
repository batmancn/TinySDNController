package BCB2009WorkspaceCreator;

# ************************************************************
# Description   : A BCB2009 Workspace Creator
# Author        : Johnny Willemsen
# Create Date   : 17/10/2008
# $Id: BCB2009WorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use BCB2007WorkspaceCreator;
use BCB2009ProjectCreator;

use vars qw(@ISA);
@ISA = qw(BCB2007WorkspaceCreator);

sub pre_workspace {
  my($self, $fh) = @_;
  my $crlf = $self->crlf();

  ## This identifies it as a Borland C++Builder 2009 file
  print $fh '﻿<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003">', $crlf;

  ## Optionally print the workspace comment
#  $self->print_workspace_comment($fh,
#            '<!-- $Id: BCB2009WorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $ -->', $crlf,
#            '<!-- MPC Command -->', $crlf,
#            '<!-- ', $self->create_command_line_string($0, @ARGV), ' -->',
#            $crlf);
}

1;
